package exercise;

import java.util.*;

public class Main {
	public static void main(String[] Args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int q = sc.nextInt();
		ArrayList<Integer> a = new ArrayList<Integer>();
		a.add(0);
		for(int i = 1, x; i <= n; ++ i) {
			x = sc.nextInt();
			a.add(x);
		}
		SegmentTree tree = new SegmentTree(a);
		for(int i = 1; i <= q; ++ i){
			int operation = sc.nextInt();
			int l = sc.nextInt();
			int r = sc.nextInt();
			if (operation == 1) {
				int d = sc.nextInt();
				tree.addModify(l, r, 1, n, 1, d);
			} else {
				System.out.println(tree.query(l, r, 1, n, 1));
			}
		}
		sc.close();
	}
}