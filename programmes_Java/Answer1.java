import java.util.*;
public class Answer1{
    public static void main(String args[]){
        Scanner cin = new Scanner(System.in);
        String[] s = cin.nextLine().split("\\s+");
        int m = cin.nextInt();
        int[] nums1= new int[s.length];
        for(int i = 0; i < m; ++ i) nums1[i] = Integer.parseInt(s[i]);
        s = cin.nextLine().split("\\s+");
        int n = cin.nextInt();
        for(int i = 0; i < n; ++ i) nums1[i+m] = Integer.parseInt(s[i]);
        Arrays.sort(nums1, 0, m + n - 1);
        for(int i = 0; i < m + n - 1; ++ i) System.out.print(nums1[i] + ' ');
        cin.close();
    }
}