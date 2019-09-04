package com.wengzc.testcpphttpclient;

import android.Manifest;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;


public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        //System.loadLibrary("crypto");
        //System.loadLibrary("ssl");
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        checkPermission();

        // Example of a call to a native method
        TextView tv = findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());
        tv.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                testFun();
            }
        });

    }

    private void checkPermission (){
        if (PermissionUtil.needRequestPermissions(this, Manifest.permission.INTERNET)){
            PermissionUtil.requestPermissions(this, 7788, Manifest.permission.INTERNET);
        }
    }

    public void testFun (){
        new Thread(){

            @Override
            public void run() {
                testJni();
            }

        }.start();
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public native void testJni();

}
