import java.sql.*;
public class DeleteShu{  
  public static void main(String[ ] args)
   {
    String JDriver="sun.jdbc.odbc.JdbcOdbcDriver";
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
   //ɾ���ڶ�����¼
      PreparedStatement ps=con.prepareStatement(
                "delete from student1 where id=?");
      ps.setString(1,"0002");
      ps.executeUpdate( ); //ִ��ɾ��
    //��ѯ���ݿⲢ�����ݱ�������������Ļ��
      ResultSet rs=s.executeQuery("select * from student1");    
      while(rs.next( ))
       {  System.out.println(rs.getString("id")+"\t"+
                rs.getString("name")+"\t" + rs.getString("score"));
      }
      s.close( );
      con.close( );
    }
    catch(SQLException e){
      System.out.println("SQLException: " +e.getMessage( ));
    }
  }
}
