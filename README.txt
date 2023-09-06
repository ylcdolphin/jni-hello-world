// Create header
javac -h . Hello/World/JNI/CustomJNICpp.java
// Compile lib
gcc -I"C:\Program Files\Java\jdk1.8.0_131\include" -I"C:\Program Files\Java\jdk1.8.0_131\include\win32" -I. -c Hello/World/JNI/CustomJNICpp.c -o Hello/World/JNI/CustomJNICpp.o
g++ -I"C:\Program Files\Java\jdk1.8.0_131\include" -I"C:\Program Files\Java\jdk1.8.0_131\include\win32" -I. -c Hello/World/JNI/CustomJNICppImpl.cpp -o Hello/World/JNI/CustomJNICppImpl.o
ld -r Hello/World/JNI/CustomJNICpp.o Hello/World/JNI/CustomJNICppImpl.o -o Hello/World/JNI/nativecombine.o
g++ '-Wl,--add-stdcall-alias' -I"C:\Program Files\Java\jdk1.8.0_131\include" -I"C:\Program Files\Java\jdk1.8.0_131\include\win32" -I. -shared -o nativeCombine.dll Hello/World/JNI/nativeCombine.o
// Compile java
javac Hello/World/JNI/CustomJNICpp.java
// Execute java
java Hello.World.JNI.CustomJNICpp

// Note: dll should be put in root folder
//       java should be execute from root foler