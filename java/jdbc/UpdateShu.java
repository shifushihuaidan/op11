import java.sql.*;
public class UpdateShu{ 
  public static void main(String[ ] args) {
    String JDriver="sun.jdbc.odbc.JdbcOdbcDriver";
    String conURL="jdbc:odbc:TestDB";
    String[ ] id={"0002","0003"};
    int[ ] score={89,60};
try {
      Class.forName(JDriver);
    }
    catch(java.lang.ClassNotFoundException e) {
      System.out.println("ForName :" + e.getMessage( ));
    }
    try { 
      Connection con=DriverManager.getConnection(conURL);
      //�޸����ݿ������ݱ������
      PreparedStatement ps=con.prepareStatement(
           "UPDATE student1 set score=? where id=? ");
      int i=0,idlen=id.length;
   do{ ps.setInt(1,score[i]);
          ps.setString(2,id[i]);
          ps.executeUpdate( );//ִ��SQL�޸�����
          ++i;
      }while(i<id.length);
      ps.close( );      
      //��ѯ���ݿⲢ�����ݱ�������������Ļ��
      Statement s=con.createStatement( );
      ResultSet rs=s.executeQuery("select * from student1");
      while(rs.next( )) {
        System.out.println(rs.getString("id") +
                "\t" + rs.getString("name")+
                "\t" + rs.getInt("score"));
}
      s.close( );
      con.close( );
    }
    catch(SQLException e) {
      System.out.println("SQLException: " +e.getMessage( ));
    }
  }
}
