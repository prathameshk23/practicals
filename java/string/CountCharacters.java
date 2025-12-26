import java.util.Scanner;

public class CountCharacters {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter a string: ");
    String str = sc.nextLine();
    int vowels = 0, consonants = 0, digits = 0, spaces = 0;
    str = str.toLowerCase();
    for (int i = 0; i < str.length(); i++) {
      char ch = str.charAt(i);
      if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
        vowels++;
      } else if (ch >= 'a' && ch <= 'z') {
        consonants++;
      } else if (ch >= '0' && ch <= '9') {
        digits++;
      } else if (ch == ' ') {
        spaces++;
      }
    }
    System.out.println("Vowels: " + vowels);
    System.out.println("Consonants: " + consonants);
    System.out.println("Digits: " + digits);
    System.out.println("Spaces: " + spaces);
    sc.close();
  }
}
