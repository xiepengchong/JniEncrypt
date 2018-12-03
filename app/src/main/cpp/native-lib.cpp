#include <jni.h>
#include <string>
#include "aes/aes_jni.h"
#include "base64/encrypt.h"

extern "C" JNIEXPORT jstring

JNICALL
Java_com_encrypt_jni_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C" JNIEXPORT jstring

JNICALL
Java_com_encrypt_jni_MainActivity_encrypt(
        JNIEnv *env,
        jobject /* this */,jstring str_) {
    const char *str = env->GetStringUTFChars(str_, 0);

    // TODO

    const unsigned char *master_key = (const unsigned char *) "1234567890abcdef";
    const unsigned char *iv = (const unsigned char *) "90abcdef12345678";

    std::string h = EncodeAES(master_key, str, iv);

    env->ReleaseStringUTFChars(str_, str);
    return env->NewStringUTF(h.c_str());
}
extern "C" JNIEXPORT jstring

JNICALL
Java_com_encrypt_jni_MainActivity_decrypt(
        JNIEnv *env,
        jobject /* this */,jstring str_) {
    const char *str = env->GetStringUTFChars(str_, 0);

    // TODO

    const unsigned char *master_key = (const unsigned char *) "1234567890abcdef";

    const unsigned char *iv = (const unsigned char *) "90abcdef12345678";

    std::string s = DecodeAES(master_key,str,iv);
    env->ReleaseStringUTFChars(str_, str);

    return env->NewStringUTF(s.c_str());
}


extern "C" JNIEXPORT jstring

JNICALL
Java_com_encrypt_jni_MainActivity_encryptBase64(
        JNIEnv *env,
        jobject /* this */,jstring str_,jstring key_) {
    const char *cPassword = env->GetStringUTFChars(str_, 0);
    const char *cKey = env->GetStringUTFChars(key_, 0);
    std::string jpassword = std::string(cPassword);
    std::string jKey = std::string(cKey);
    std::string output = encrypt(jpassword,jKey);
    return env->NewStringUTF(output.c_str());
}



extern "C" JNIEXPORT jstring

JNICALL
Java_com_encrypt_jni_MainActivity_decryptBase64(
        JNIEnv *env,
        jobject /* this */,jstring str_,jstring key_) {
    const char *cEncode = env->GetStringUTFChars(str_, 0);
    std::string sEncode = std::string(cEncode);
    const char *ckey = env->GetStringUTFChars(key_, 0);
    std::string keyStr = std::string(ckey);
    std::string output = decrypt(sEncode,keyStr );
    return env->NewStringUTF(output.c_str());
}
