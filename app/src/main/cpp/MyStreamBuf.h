//
// Created by wengzc on 2019/8/16.
//

#ifndef CPPSTDLIBSTUDY_MYSTREAMBUF_H
#define CPPSTDLIBSTUDY_MYSTREAMBUF_H

#include <iostream>
#include <streambuf>
#include <android/log.h>

using namespace std;

class MyStreamBuf : public streambuf {

    enum {
        BUFFER_SIZE = 255,
    };

public:

    MyStreamBuf (){
        buffer_[BUFFER_SIZE] = '\0';
        setp(buffer_, buffer_ + BUFFER_SIZE - 1);
    }

    ~MyStreamBuf(){
        sync();
    }

protected:

    virtual int_type  overflow (int_type c){
        if (c != EOF){
            *pptr() = c;
            pbump(1);
        }
        flush_buffer();
        return c;
    }

    virtual int sync (){
        flush_buffer();
        return 0;
    }

private :

    int flush_buffer (){
        int len = int(pptr() - pbase());
        if (len <= 0){
            return 0;
        }

        if (len <= BUFFER_SIZE){
            buffer_[len] = '\0';
        }

        android_LogPriority t = ANDROID_LOG_INFO;
        __android_log_write(t, "xxx", buffer_);
        pbump(-len);
        return len;
    }

    char buffer_[BUFFER_SIZE+1];
};

#endif //CPPSTDLIBSTUDY_MYSTREAMBUF_H
