# Building and Running a JNI Project

## Prerequisites
- Java Development Kit (JDK)
- GCC (GNU Compiler Collection)

## Build Steps

### 1. Create Header
```bash
javac -h . Hello/World/JNI/CustomJNICpp.java
```

### 2. Compile lib
```bash
gcc -I"C:\Program Files\Java\jdk1.8.0_131\include" -I"C:\Program Files\Java\jdk1.8.0_131\include\win32" -I. -c Hello/World/JNI/CustomJNICpp.c -o Hello/World/JNI/CustomJNICpp.o
g++ -I"C:\Program Files\Java\jdk1.8.0_131\include" -I"C:\Program Files\Java\jdk1.8.0_131\include\win32" -I. -c Hello/World/JNI/CustomJNICppImpl.cpp -o Hello/World/JNI/CustomJNICppImpl.o
ld -r Hello/World/JNI/CustomJNICpp.o Hello/World/JNI/CustomJNICppImpl.o -o Hello/World/JNI/nativecombine.o
g++ '-Wl,--add-stdcall-alias' -I"C:\Program Files\Java\jdk1.8.0_131\include" -I"C:\Program Files\Java\jdk1.8.0_131\include\win32" -I. -shared -o nativeCombine.dll Hello/World/JNI/nativeCombine.o
```

### 3. Compile java
```bash
javac Hello/World/JNI/CustomJNICpp.java
```

### 4. Execute java
```bash
java Hello.World.JNI.CustomJNICpp
```

## Note: 
* dll should be put in the root folder
* Java should be execute from the root folder
