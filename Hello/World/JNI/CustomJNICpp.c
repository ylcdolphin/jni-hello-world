#include <jni.h>
#include <stdio.h>
#include "Hello_World_JNI_TestJNI.h"
#include "CustomJNICppImpl.h"

JNIEXPORT void JNICALL Java_Hello_World_JNI_TestJNI_sayHello(JNIEnv *env, jobject thisObj, jint num, jstring name)
{
    // Convert java type to C type
    const char *nameChar = (*env)->GetStringUTFChars(env, name, NULL);

    // Invoke C++ function
    int code = sayHello(num, nameChar);

    // Handle exception based on the returned error code from C++
    jclass exceptionClass = (*env)->FindClass(env, "java/lang/Exception");
    if (code == 1)
    {
        printf("JNI: thow exception\n");
        (*env)->ThrowNew(env, exceptionClass, "num should be positive");
    }

    return;
}