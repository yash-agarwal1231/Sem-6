import java.sql.*;

class DisplayStudent{
  public static void main(String[] args){
    String url = "jdbc:postgresql://192.168.0.102:5432/tycsdb3";
    String user = "tycs3";
    String password = "";
     try{
      Class.forName("org.postgresql.Driver");
      Connection con = DriverManager.getConnection(url,user,password);
      Statement stmt = con.createStatement();
      ResultSet rs = stmt.executeQuery("Select * from student");
      while(rs.next()){
        System.out.println(rs.getInt(1)+" "+rs.getString(2)+" "+rs.getInt(3));
        
      }
      rs.close();
      con.close();
  }catch(Exception e){
      e.printStackTrace();
    }
}
}
