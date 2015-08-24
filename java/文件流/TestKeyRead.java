import java.io.*;
class TestKeyRead  {
	public static void main(String args[]) {
		int b;
		System.out.println("请输入内容，以回车结束");
		//try{
		  while((b=System.in.read())!=-1){
			System.out.print((char)b);   }
	        //}catch(IOException   e ){
	     //System.out.println(e.toString());}
	}
}
