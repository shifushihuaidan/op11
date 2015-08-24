  import java.io.*;
  class filestream
 {  public static void main(String args[])
    { try{
      File inFile=new File("file1.txt");
      File outFile=new File("file2.txt");
      FileInputStream fis=new FileInputStream(inFile);
      FileOutputStream fos=new  FileOutputStream(outFile);
	  int c;  while((c=fis.read())!=-1)  fos.write(c);
      fis.close(); fos.close();
	}catch(FileNotFoundException e) {
    	System.out.println("FileStreamsTest: "+e);
	}catch(IOException e) {
		System.err.println("FileStreamsTest: "+e);
	}}}
