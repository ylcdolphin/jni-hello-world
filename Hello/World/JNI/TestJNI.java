package Hello.World.JNI;

public class TestJNI {
   static {
      // Load dll/so
      System.loadLibrary("native");
   }

   // Native method declaration
   private native void sayHello(int num, String name);

   public static void main(String[] args) {
      try {
         // Test the native method
         TestJNI myTest = new TestJNI();
         myTest.sayHello(99, "JACK"); // Invoke native method
         myTest.sayHello(-1, "JACK"); // Invoke native method
      } catch (Exception e) {
         // Handle exception thrown by the JNI
         System.out.println("Java: " + e.getMessage());
      }
   }
}
