import java.sql.*;

public class DisplayRecords {
  public static void main(String[] args) {
    String url = "jdbc:mysql://localhost:3306/company";
    String user = "root";
    String password = "root";
    try {
      Class.forName("com.mysql.cj.jdbc.Driver");
      Connection con = DriverManager.getConnection(url, user, password);
      String query = "SELECT * FROM employees";
      Statement stmt = con.createStatement();
      ResultSet rs = stmt.executeQuery(query);
      System.out.println("Id"
                         + "\t"
                         + "Name"
                         + "\t\t"
                         + "Department"
                         + "\t"
                         + "Salary");
      while (rs.next()) {
        System.out.println(rs.getInt(1) + "\t" + rs.getString(2) + "\t" +
                           rs.getString(3) + "\t" + rs.getInt(4));
      }
      rs.close();
      stmt.close();
      con.close();
    } catch (Exception e) {
      System.out.println(e);
    }
  }
}
