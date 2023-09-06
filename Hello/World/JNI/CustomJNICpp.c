#include <jni.h>
#include <stdio.h>
#include "Hello_World_JNI_CustomJNICpp.h"
#include "CustomJNICppImpl.h"
 
JNIEXPORT void JNICALL Java_Hello_World_JNI_CustomJNICpp_sayHello (JNIEnv *env, jobject thisObj, jint num, jstring name) {
    const char *nameChar = (*env)->GetStringUTFChars(env, name, NULL);
    sayHello(num, nameChar);  // invoke C++ function
    return;
}