
 //ͳ��һ���ļ���Ԫ������
package ch10;

import java.io.*;

public class StatVowl 
{
   public static void main(String args[]) {
   int numA = 0, numE = 0, numI = 0, numO = 0, numU = 0;//��¼Ԫ���ĸ���
   int ch;
 try {
   FileInputStream fin = new FileInputStream(new File("example\\ex10_1.txt"));
   ch = fin.read();//��һ���ַ�
   while (ch != -1) 
   {
     switch ((char)ch) 
     {
      case 'a':numA++;break;
      case 'e':numE++;break;
      case 'i':numI++;break;
      case 'o':numO++;break;
      case 'u':numU++;break;
     }
    ch = fin.read();
    }
   fin.close();//�ر��ļ�
    System.out.println("  a,e,i,o,u�ĸ����ֱ�Ϊ" + numA + "  " + numE + "  "
+ numI + "  " + numO + "  " + numU + "  ");
   } 
   catch (FileNotFoundException e) 
     {
       System.out.println(e);
     } 
   catch (IOException e) 
     {
     System.out.println(e);
     } 
  }
 }

