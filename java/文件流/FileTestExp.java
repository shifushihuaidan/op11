import java.io.*;
public class FileTestExp{
	public static void main(String args[])     
                                         throws IOException  {
     File dir=new File("\\root"); 
     File f1=new File(dir,   "fileOne.txt");
     File f2=new File(dir,   "fileTwo.java");
            // �ļ����󴴽���ָ�����ļ���Ŀ¼��һ�������ϴ���
      if (!dir.exists())     dir.mkdir(); 
      if (!f1.exists())      f1.createNewFile();
      if (!f2.exists())	     f2.createNewFile();
      System.out.println("f1's AbsolutePath= " +f1.getAbsolutePath());
System.out.println("f1 Canread="+f1.canRead());
System.out.println("f1's len= "+f1.length());    
String []FL;  int count=0;       FL=dir.list( );
for(int i=0;i<FL.length;i++){    count++;
      System.out.println(  FL[i]+"is in \\root");}
System.out.println("there are"+count+"file in //root");   }
}
