import java.io.*;
class testAccessFile{
   public static void main(String args[]){	
	try{RandomAccessFile  rf1=new  
         RandomAccessFile("testAccess.txt","rw"); 
	    rf1.writeBytes("Linda ");		  
	    rf1.writeBytes("21 ");
	    rf1.writeBytes("female ");
          rf1.writeBytes("Computer Depart ");
	    rf1.seek(rf1.length());
	    rf1.writeUTF("hello everyone");  	 }
      catch (Exception e){
	     System.out.println(e.toString());  }	    
	}}
