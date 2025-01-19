package exercise;

import java.util.*;

public class BFS {
	private static final int N = 100010;
	private static final int INF = 0x7fffffff;
	private static int[] head = new int[N];
	private static int[] distance = new int[N];
	private static boolean[] visited = new boolean[N];
	private static int[] father = new int[N];
	private static int[] to = new int[N << 1], next = new int[N << 1];
	private static int idx = 0;
	
	public static void addEdge(int u, int v) {
		to[idx] = v;
		next[idx] = head[u];
		head[u] = idx;
		idx ++;
	}
	
	public static void main(String[] Args){
		Arrays.fill(head, -1);
		Arrays.fill(father, -1);
		Arrays.fill(distance, INF);
		Arrays.fill(visited, false);
		Arrays.fill(to, 0);
		Arrays.fill(next, 0);
		
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt(), m = sc.nextInt();
		
		for(int i = 0; i < m; ++ i){
			int u = sc.nextInt();
			int v = sc.nextInt();
			addEdge(u, v);
			addEdge(v, u);
		}
		
		int s = sc.nextInt(), t = sc.nextInt();
		
		CircleQueue queue = new CircleQueue(50);
		queue.add(s);
		distance[s] = 0;
		
		while(!queue.isEmpty()){
			int u = queue.get();
			if(visited[u]) continue;
			visited[u] = true;
			for(int i = head[u]; i != -1; i = next[i]){
				int v = to[i];
				if(distance[u] + 1 < distance[v]) {
					distance[v] = distance[u] + 1;
					father[v] = u;
				}
				queue.add(v);
			}
		}
		ArrayList<Integer> route = new ArrayList<Integer>();
		while(t != -1) {
			route.add(t);
			t = father[t];
		}
		for(int i = route.size() - 1; i > 0; -- i)
			System.out.printf("T%d->",route.get(i) - 1);
		System.out.printf("T%d\n",route.get(0) - 1);
		System.out.printf("%d Edges",route.size() - 1);
		sc.close();
	}
}