#define CPPHTTPLIB_OPENSSL_SUPPORT

#include <jni.h>
#include <string>

#include "httplib.h"
#include "MyStreamBuf.h"
#include <openssl/ssl.h>

extern "C" JNIEXPORT jstring JNICALL
Java_com_wengzc_testcpphttpclient_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}



extern "C" JNIEXPORT void JNICALL
Java_com_wengzc_testcpphttpclient_MainActivity_testJni(
        JNIEnv *env,
        jobject /* this */) {
    MyStreamBuf myStreamBuf;
    std::cout.rdbuf(&myStreamBuf);

    std::cout << "zzzzww" << endl;

    //httplib::Client client("www.baidu.com", 80);

    try {
        httplib::SSLClient client("www.douban.com", 443);
        client.enable_server_certificate_verification(false);

        auto res = client.Get("/");
        //std::cout << res->status << std::endl;

        if (res && res->status == 200){
            std::cout << res->body << std::endl;
        }
    }catch (...){
        std::cout << "ssl exception here" << std::endl;
    }

}
