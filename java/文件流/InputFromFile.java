//��һ���ļ��ж����ݣ��������ļ�����
import java.io.*;
class InputFromFile
{
public static void main(String args[])
{ 
  try
   {	
       FileInputStream rf=new   FileInputStream("ex.txt");
   	   int n=512;   
   	   byte  buffer[]=new  byte[n];   
       while((rf.read(buffer,0,n)!=-1)&&(n>0)){  
           System.out.println(new String(buffer) );
    }
   System.out.println();
   rf.close();
   } 
  catch(IOException  IOe){	    
  System.out.println(IOe.toString());
   }
}
}