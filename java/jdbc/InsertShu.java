import java.sql.*;
public class InsertShu{  
  public static void main(String[ ] args) {
    String JDriver = "sun.jdbc.odbc.JdbcOdbcDriver";
    String conURL="jdbc:odbc:TestDB";
    try {
      Class.forName(JDriver);
    }
catch(java.lang.ClassNotFoundException e) {
      System.out.println("ForName :" + e.getMessage( ));
    }
    try {
      Connection con=DriverManager.getConnection(conURL);
      Statement s=con.createStatement( );      
      String r1="insert into student1 values("+"'0001','����',80)";
      String r2="insert into student1 values("+"'0002','��ǿ',94)";
      String r3="insert into student1 values("+"'0003','����',82)";
      //ʹ��SQL ����insert��������ѧ����¼������
      s.executeUpdate(r1);
      s.executeUpdate(r2);
      s.executeUpdate(r3);
      s.close( );
      con.close( );
    }
    catch(SQLException e) 
    {

      System.out.println("SQLException: " +e.getMessage( ));
     }
  }
}
