import java.util.ArrayList;
import java.util.Scanner;

public class StudentList {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    ArrayList<String> students = new ArrayList<>();
    System.out.print("Enter number of students: ");
    int n = sc.nextInt();
    sc.nextLine();
    System.out.println("Enter student names:");
    for (int i = 0; i < n; i++) {
      String name = sc.nextLine();
      students.add(name);
    }
    System.out.println("Student List:");
    for (String s : students) {
      System.out.println(s);
    }
    sc.close();
  }
}
