import java.io.*;
class  CopyFileToFile{
  public static void main(String args[]){
     try{
          File  inFile=new File("CopyFileToFile.java");
          File  outFile=new File("copy2.java");
          FileInputStream  finS=new  FileInputStream(inFile);
          FileOutputStream  foutS=new  FileOutputStream(outFile);
          int c;  
          while(  (c=finS.read())!=-1 ) {
          foutS.write(c);                   }
          finS.close();     
          foutS.close();
         }catch(IOException e) {
		System.err.println("FileStreamsTest: "+e);}
}}
