import java.io.*;
class Student implements Serializable
{ int id;      String name; 
   int age;   String department;
   public Student(int id, String name,int age,String department){
      this.id=id;  this.name=name;
      this.age=age; 
      this.department=department;
   }
}

public class Objectser{
  public static void main(String args[]){
  	 Student stu=new Student(981036,"Li Ming",16,"CSD");
     try {
     	FileOutputStream fo=new FileOutputStream("date.ser");
        ObjectOutputStream so=new ObjectOutputStream(fo);
        so.writeObject(stu);so.close();
      }catch(Exception e) {      }

   //  Student stu=null;
    try{
        FileInputStream fi=new FileInputStream("date.ser");
        ObjectInputStream si=new   ObjectInputStream(fi);
        stu=(Student)si.readObject();
        si.close();
     }catch(Exception e) {System.out.println(e.toString());    }
     System.out.println("ID: "+stu.id+"name:"+stu.name+"age:"+stu.age+"dept.:"+stu.department);
  } }
  
