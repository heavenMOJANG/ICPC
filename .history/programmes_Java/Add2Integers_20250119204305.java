import java.util.*;

public class Add2Integers {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n1 = sc.nextInt();
        int n2 = sc.nextInt();
        int total = n1 + n2;
        System.out.println("The total is " + total + ".");
        sc.close();
    }
}
