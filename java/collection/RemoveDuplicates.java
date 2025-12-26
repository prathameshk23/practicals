import java.util.*;

public class RemoveDuplicates {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter number of strings: ");
    int n = sc.nextInt();
    sc.nextLine();
    HashSet<String> set = new HashSet<>();
    System.out.println("Enter the strings:");
    for (int i = 0; i < n; i++) {
      String str = sc.nextLine();
      set.add(str);
    }
    System.out.println("Strings after removing duplicates:");
    for (String s : set) {
      System.out.println(s);
    }
    sc.close();
  }
}
