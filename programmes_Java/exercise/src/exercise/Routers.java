package exercise;

import java.util.*;

public class Routers {
	private static final int N = 100010;
	private static final int INF = 0x7fffffff;
	private static int[] head = new int[N];
	private static int[] distance = new int[N];
	private static boolean[] visited = new boolean[N];
	private static int[] father = new int[N];
	private static int[] to = new int[N << 1], next = new int[N << 1];
	private static int idx = 0;
	
	private static void addEdge(int u, int v) {
		to[idx] = v;
		next[idx] = head[u];
		head[u] = idx;
		idx ++;
	}
	
	public static void pathSearch(int s, int t){
		Arrays.fill(head, -1);
		Arrays.fill(father, -1);
		Arrays.fill(distance, INF);
		Arrays.fill(visited, false);
		Arrays.fill(to, 0);
		Arrays.fill(next, 0);
		
		addEdge(1,2);addEdge(2,1);
		addEdge(1,6);addEdge(6,1);
		addEdge(2,3);addEdge(3,2);
		addEdge(2,6);addEdge(6,2);
		addEdge(2,8);addEdge(8,2);
		addEdge(3,4);addEdge(4,3);
		addEdge(4,6);addEdge(6,4);
		addEdge(5,6);addEdge(6,5);
		addEdge(5,9);addEdge(9,5);
		addEdge(6,11);addEdge(11,6);
		addEdge(7,8);addEdge(8,7);
		addEdge(7,9);addEdge(7,11);
		addEdge(8,11);addEdge(11,8);
		addEdge(9,12);addEdge(12,9);
		addEdge(10,12);addEdge(12,10);
		
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
		System.out.printf("The shortest path from R%d to R%d is:\n",s,t);
		while(t != -1) {
			route.add(t);
			t = father[t];
		}
		for(int i = route.size() - 1; i > 0; -- i)
			System.out.printf("R%d->",route.get(i));
		System.out.printf("R%d\n",route.get(0));
		System.out.printf("%d Edges marked.",route.size() - 1);
	}
}
class CircleQueue {
	private int maxSize;
    private int head;
    private int rear;
    private int[] arr;
    public CircleQueue(int arrMaxSize){
        maxSize = arrMaxSize;
        arr = new int[maxSize];
    }
    public boolean isFull(){
        return (rear + 1) % maxSize == head;
    }
    public boolean isEmpty(){
        return rear == head;
    }
    public void add(int n){
        if(isFull()){
            System.out.println("FULL QUEUE ERROR.");
            return;
        }
        arr[rear] = n;
        rear = ( rear + 1) % maxSize;
    }
    public int get(){
        if(isEmpty()){
            throw new RuntimeException("EMPTY QUEUE ERROR");
        }
        int value = arr[head];
        head = (head + 1) % maxSize;
        return value;
    }
}