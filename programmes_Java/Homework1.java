import java.util.*;
public class Homework1 {
    public static void main(String Args[]){
        Scanner sc = new Scanner(System.in);
        double N = sc.nextDouble();
        double t = 5730 * Math.log(N / 13.6) / Math.log(0.5);
        System.out.println(t);
        sc.close();
    }
}