import java.io.*;
class OutputFile
{
public static void main(String args[])
{ 
  try{ 
     System.out.println("please Input from   Keyboard");
    int count,n=512;	     
    byte buffer[]=new byte[n];
    count=System.in.read(buffer);
  FileOutputStream wf= new   FileOutputStream("example/write.txt");
  wf.write(buffer,0,count);
  wf.close();          //����д��������ʱ������close�����ر�����
  System.out.println("Save to the write.txt");
}catch(IOException  IOe){
    System.out.println("File Write Error!");
}

}
}