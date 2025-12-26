import java.sql.*;
import java.util.Scanner;

public class InsertStudent {
  public static void main(String[] args) {
    String url = "jdbc:mysql://localhost:3306/students";
    String user = "root";
    String password = "root";
    Scanner sc = new Scanner(System.in);
    try {
      Class.forName("com.mysql.cj.jdbc.Driver");
      Connection con = DriverManager.getConnection(url, user, password);
      System.out.print("Enter student name: ");
      String name = sc.nextLine();

      System.out.print("Enter student email: ");
      String email = sc.nextLine();

      String query = "INSERT INTO students (name, email) VALUES (?, ?)";

      PreparedStatement pst = con.prepareStatement(query);
      pst.setString(1, name);
      pst.setString(2, email);
      int result = pst.executeUpdate();
      if (result > 0) {
        System.out.println("Record inserted successfully!");
      }
      pst.close();
      con.close();
    } catch (Exception e) {
      System.out.println(e);
    }
    sc.close();
  }
}
