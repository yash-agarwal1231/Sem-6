import java.sql.*;

class CreateStudentTable{
  public static void main(String[] args){
    String url = "jdbc:postgresql://192.168.0.102:5432/tycsdb3";
    String user = "tycs3";
    String password = "";
    try{
      Class.forName("org.postgresql.Driver");
      Connection con = DriverManager.getConnection(url,user,password);
      Statement stmt = con.createStatement();
      
      String createTable = "Create Table if not exists student("+"id INT, name varchar(50),marks int)";
      stmt.execute(createTable);
      
      String insert = "Insert into student values(18,'Tanishaa',78),(3,'Yash',85)";
      stmt.executeUpdate(insert);
      System.out.println("Table Created and Records Inserted");
      stmt.close();
      con.close();
    }catch(Exception e){
      e.printStackTrace();
    }
  }
}
