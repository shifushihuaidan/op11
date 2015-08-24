import java.sql.*;  //引入java.sql包
public class ShuJuKu{
  public static void main(String[ ] args) {
    String JDriver = "sun.jdbc.odbc.JdbcOdbcDriver";  //声明JDBC驱动程序对象
    String conURL="jdbc:odbc:TestDB";  //定义JDBC的URL对象
    try {
      Class.forName(JDriver);  //加载JDBC-ODBC桥驱动程序
    }

   catch(java.lang.ClassNotFoundException e) {
      System.out.println("ForName :" + e.getMessage( ));
    }
    try {
      Connection con=DriverManager.getConnection(conURL);  //连接数据库URL
      Statement s=con.createStatement( );  //建立Statement类对象
      String query = "create table student1 ( " 
                      + "id char(10)," 
                      + "name char(15)," 
                      + "score integer"
                      + ")";  //创建一个含有三个字段的学生表student
      s.executeUpdate(query);  //执行
            s.close( );  //释放Statement所连接的数据库及JDBC资源
      con.close( );  //关闭与数据库的连线
    }
    catch(SQLException e){ System.out.println("SQLException: " +e.getMessage( ));  }
  }
}
