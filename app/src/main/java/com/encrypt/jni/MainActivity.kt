package com.encrypt.jni

import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        // Example of a call to a native method
        sample_text.text = stringFromJNI()

        var output = encrypt("2222222222");
        Log.v("XPC","encode="+output)
        Log.v("XPC","decrypt="+decrypt(output))


        var outputBase = encryptBase64("2222222222","abcdef");
        Log.v("XPC","encryptBase64="+outputBase)
        Log.v("XPC","decryptBase64="+decryptBase64(outputBase,"abcdef"))

    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String
    external fun encrypt(input:String): String
    external fun decrypt(input:String): String


    external fun decryptBase64(input:String,key:String): String
    external fun encryptBase64(input:String,key:String): String

    companion object {

        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("native-lib")
        }
    }
}
