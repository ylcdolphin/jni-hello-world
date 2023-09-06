#include <jni.h>
#include "CustomJNICppImpl.h"
#include <iostream>
 
using namespace std;


void sayHello (jint num, const char *name) {
    string userName = name;
    cout << "Hello World from " << num << "-" << name << "!" << endl;
}