package Hello.World.JNI;

public class TestJNI {
   static {
      // Load dll/so
      System.loadLibrary("native");
   }

   // Native method declaration
   private native void sayHello(int num, String name);

   public static void main(String[] args) {
      // Test the native method
      new TestJNI().sayHello(99, "JACK"); // Invoke native method
   }
}
