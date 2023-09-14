#include <jni.h>
#include <stdio.h>
#include "Hello_World_JNI_TestJNI.h"
#include "CustomJNICppImpl.h"

JNIEXPORT void JNICALL Java_Hello_World_JNI_TestJNI_sayHello(JNIEnv *env, jobject thisObj, jint num, jstring name)
{
    // Convert java type to C type
    const char *nameChar = (*env)->GetStringUTFChars(env, name, NULL);

    // Invoke C++ function
    sayHello(num, nameChar);

    return;
}