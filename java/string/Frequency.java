import java.util.Scanner;

public class Frequency {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter a string: ");
    String str = sc.nextLine();
    String counted = "";
    for (int i = 0; i < str.length(); i++) {
      char ch = str.charAt(i);
      if (counted.indexOf(ch) != -1) {
        continue;
      }
      int count = 0;
      for (int j = 0; j < str.length(); j++) {
        if (str.charAt(j) == ch) {
          count++;
        }
      }
      System.out.println(ch + " : " + count);
      counted += ch;
    }
    sc.close();
  }
}
