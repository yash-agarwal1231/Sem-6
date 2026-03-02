import java.sql.*;

class DBConnect{
  public static void main(String[] args){
    String url = "jdbc:postgresql://192.168.0.102:5432/tycsdb3";
    String user = "tycs3";
    String password = "";
    
    try{
      Class.forName("org.postgresql.Driver");
      Connection con = DriverManager.getConnection(url,user,password);
      System.out.println("Connected to PostgreSQL!");
      con.close();
    }
    catch(Exception e){
      e.printStackTrace();
    }
  }
}
