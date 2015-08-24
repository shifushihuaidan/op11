import java.io.*;
class TestReadByteArray
{
public static void main(String args[])
{ 
  try
   {	
       byte []  buffer=new byte[512];
       System.out.println("please Input:");
       int count=System.in.read(buffer);
       System.out.println("Output:");	
      for(int i=0;i<count;i++){
      System.out.print("  "  + buffer[i] );  }		
       System.out.println();
      for(int i=0;i<count;i++){
      System.out.print((char) buffer[i]);   }
      String s=new String(buffer);
      System.out.println(s);  
      System.out.println(count); 
   }
  catch(IOException  e){	    
  System.out.println(e.toString());
   }
}
}