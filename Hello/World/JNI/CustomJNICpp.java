package Hello.World.JNI;

// import java.awt.image.BufferedImage;
// import java.io.ByteArrayOutputStream;
// import java.io.File;
// import java.io.IOException;

// import javax.imageio.ImageIO;

public class CustomJNICpp {
   static {
      System.loadLibrary("nativeCombine"); // hello.dll (Windows) or libhello.so (Unixes)
   }

   // Native method declaration
   private native void sayHello(int num, String name);

   // Test Driver
   public static void main(String[] args) {
      // try {
      //    BufferedImage bImage = ImageIO.read(new File("icon.png"));
      //    ByteArrayOutputStream bos = new ByteArrayOutputStream();
      //    ImageIO.write(bImage, "jpg", bos);
      //    byte[] data = bos.toByteArray();
      // } catch (IOException e) {
      //    // TODO Auto-generated catch block
      //    e.printStackTrace();
      // }
      new CustomJNICpp().sayHello(0, "JACK"); // Invoke native method
   }
}
