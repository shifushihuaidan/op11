import java.sql.*;  //����java.sql��
public class ShuJuKu{
  public static void main(String[ ] args) {
    String JDriver = "sun.jdbc.odbc.JdbcOdbcDriver";  //����JDBC�����������
    String conURL="jdbc:odbc:TestDB";  //����JDBC��URL����
    try {
      Class.forName(JDriver);  //����JDBC-ODBC����������
    }

   catch(java.lang.ClassNotFoundException e) {
      System.out.println("ForName :" + e.getMessage( ));
    }
    try {
      Connection con=DriverManager.getConnection(conURL);  //�������ݿ�URL
      Statement s=con.createStatement( );  //����Statement�����
      String query = "create table student1 ( " 
                      + "id char(10)," 
                      + "name char(15)," 
                      + "score integer"
                      + ")";  //����һ�����������ֶε�ѧ����student
      s.executeUpdate(query);  //ִ��
            s.close( );  //�ͷ�Statement�����ӵ����ݿ⼰JDBC��Դ
      con.close( );  //�ر������ݿ������
    }
    catch(SQLException e){ System.out.println("SQLException: " +e.getMessage( ));  }
  }
}
