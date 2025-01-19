package exercise;

import java.util.*;

public class MinimumCostMaximumFlow {
	private static class Edge {
        int to, nxt, f, w;
    }

    private static final int N = 5010;
    private static final int M = 50010;
    private static final int INF = 0x3f3f3f3f;
    private static Edge[] edge = new Edge[M << 1];
    private static int n, m, s, t, maxflow, mincost;
    private static int[] head = new int[N];
    private static int[] dis = new int[N];
    private static boolean[] vis = new boolean[N];
    private static int idx = 1;
    private static int[] cur = new int[N];

    private static void addEdge(int u, int v, int f, int c) {

        edge[++ idx] = new Edge();
        edge[idx].to = v;
        edge[idx].nxt = head[u];
        edge[idx].f = f;
        edge[idx].w = c;
        head[u] = idx;

        edge[++ idx] = new Edge();
        edge[idx].to = u;
        edge[idx].nxt = head[v];
        edge[idx].f = 0;
        edge[idx].w = -c;
        head[v] = idx;
    }

    private static boolean spfa() {
        Queue<Integer> q = new LinkedList<>();
        q.offer(s);
        Arrays.fill(dis, 1, n + 1, INF);
        dis[s] = 0;
        while (!q.isEmpty()) {
            int u = q.poll();
            vis[u] = false;
            for (int i = head[u]; i != 0; i = edge[i].nxt) {
                int v = edge[i].to;
                if (edge[i].f != 0 && dis[u] + edge[i].w < dis[v]) {
                    dis[v] = dis[u] + edge[i].w;
                    if (!vis[v]) {
                        q.offer(v);
                        vis[v] = true;
                    }
                }
            }
        }
        return dis[t] != INF;
    }

    private static int dfs(int u, int flow) {
        if (u == t) {
            maxflow += flow;
            return flow;
        }
        int res = 0;
        vis[u] = true;
        for (int i = cur[u]; i != 0; i = edge[i].nxt) {
            int v = edge[i].to;
            if (!vis[v] && edge[i].f != 0 && dis[v] == dis[u] + edge[i].w) {
                cur[u] = i;
                int p = dfs(v, Math.min(flow - res, edge[i].f));
                res += p;
                edge[i].f -= p;
                edge[i ^ 1].f += p;
                mincost += p * edge[i].w;
                if (res == flow) break;
            }
        }
        vis[u] = false;
        return res;
    }

    private static void dinic() {
        while (spfa()) {
            System.arraycopy(head, 0, cur, 0, head.length);
            dfs(s, INF);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        s = sc.nextInt();
        t = sc.nextInt();
        for (int i = 1; i <= m; ++i) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            int f = sc.nextInt();
            int w = sc.nextInt();
            addEdge(u, v, f, w);
        }
        dinic();
        System.out.println(maxflow + " " + mincost);
        sc.close();
    }
}
