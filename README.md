# Building and Running a JNI Project

This is a JNI example using a customized dynamic linked library. Use a deep folder structure to demonstrate the jni function naming rule.

## Prerequisites

- Java Development Kit (JDK)
- GCC (GNU Compiler Collection)

## Build Steps

### 1. Create Header

```bash
javac -h . Hello/World/JNI/TestJNI.java
```

### 2. Compile C++ lib and then native lib

This method will generate a C++ dll and a C dll.

```bash
g++ -shared -I"./Hello/World/JNI" Hello/World/JNI/CustomJNICppImpl.cpp -o CustomJNICppImpl.dll
gcc -shared -I"C:\Program Files\Java\jdk1.8.0_131\include" -I"C:\Program Files\Java\jdk1.8.0_131\include\win32" -I. -L. Hello/World/JNI/CustomJNICpp.c -o native.dll -l"CustomJNICppImpl"
```

### 2. (Alternative) Compile a combined lib

This method will combine the C++ and C codes into one dll file. However, the try-catch does not work because the C++ function is declared as an extern "C" function.

```bash
g++ -I"./Hello/World/JNI" -c Hello/World/JNI/CustomJNICppImpl.cpp -o CustomJNICppImpl.o
gcc -I"C:\Program Files\Java\jdk1.8.0_131\include" -I"C:\Program Files\Java\jdk1.8.0_131\include\win32" -I. -c Hello/World/JNI/CustomJNICpp.c -o CustomJNICpp.o
ld -r CustomJNICpp.o CustomJNICppImpl.o -o nativecombine.o
g++ '-Wl,--add-stdcall-alias' -shared nativecombine.o -o native.dll
```

### 3. Compile java

```bash
javac Hello/World/JNI/TestJNI.java
```

### 4. Execute java

```bash
java Hello.World.JNI.TestJNI
```
