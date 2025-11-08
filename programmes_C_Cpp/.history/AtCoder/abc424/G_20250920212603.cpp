#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int NODE_MAX = 30050;     // 节点上界（调整为安全值）
constexpr int EDGE_MAX = 3000005;   // 边上界（双向计数）
struct Edge { int to, nxt, cap, cst; } e[EDGE_MAX];
int head[NODE_MAX], idx;
int dis[NODE_MAX], cur[NODE_MAX], inq[NODE_MAX];
int s, t;
const long long CAP_INF = (1LL<<60);

void addEdge(int u, int v, int cap, int cst) {
    e[idx] = {v, head[u], (int)cap, cst}; head[u] = idx++;
    e[idx] = {u, head[v], 0, -cst}; head[v] = idx++;
}

// 下面复用函数名：spfa -> 构造 level graph（BFS）
bool spfa() {
    fill(dis, dis + NODE_MAX, -1);
    queue<int> q;
    dis[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = head[u]; ~i; i = e[i].nxt) {
            int v = e[i].to;
            if (e[i].cap > 0 && dis[v] == -1) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    return dis[t] != -1;
}

// dfs 保持同名，但改为 Dinic 的阻塞流 DFS
int dfs(int u, int flow) {
    if (u == t) return flow;
    for (int &i = cur[u]; ~i; i = e[i].nxt) {
        int v = e[i].to;
        if (e[i].cap > 0 && dis[v] == dis[u] + 1) {
            int pushed = dfs(v, min(flow, (int)e[i].cap));
            if (pushed > 0) {
                e[i].cap -= pushed;
                e[i ^ 1].cap += pushed;
                return pushed;
            }
        }
    }
    return 0;
}

// mcmf 名称保留，但现在返回的是 maxflow（即最小割容量）
long long mcmf() {
    long long flow = 0;
    while (spfa()) {
        // 初始化当前弧
        memcpy(cur, head, sizeof(head));
        while (true) {
            int pushed = dfs(s, (int)CAP_INF);
            if (!pushed) break;
            flow += pushed;
        }
    }
    return flow;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fill(head, head + NODE_MAX, -1);
    idx = 0;

    int N, M; // N: idols, M: songs
    cin >> N >> M;
    vector<int> A(N+1);
    for (int i = 1; i <= N; ++i) cin >> A[i];
    vector<int> B(M+1);
    vector<long long> C(M+1);
    long long SUMC = 0;
    for (int j = 1; j <= M; ++j) {
        cin >> B[j] >> C[j];
        SUMC += C[j];
    }

    // 节点编号安排（保持你要求的风格）
    s = 0;
    int songStart = 1;
    int curNode = songStart + M; // req 开始
    vector<int> reqStart(M+1);
    for (int j = 1; j <= M; ++j) {
        reqStart[j] = curNode;
        curNode += B[j];
    }
    int idolStart = curNode;
    curNode += N;
    t = curNode;
    // 确保节点数不会超界（若超界请调 NODE_MAX）
    if (t + 5 >= NODE_MAX) {
        // 防御性提示：NODE_MAX 太小
        cerr << "Error: increase NODE_MAX\n";
        return 0;
    }

    // source -> song (容量 = C[j])
    for (int j = 1; j <= M; ++j) {
        if (C[j] > 0) addEdge(s, songStart + j - 1, (int)C[j], 0);
    }
    // song -> req (容量 = INF)
    for (int j = 1; j <= M; ++j) {
        for (int k = 0; k < B[j]; ++k) {
            addEdge(songStart + j - 1, reqStart[j] + k, (int)min(CAP_INF, (long long)CAP_INF), 0);
        }
    }
    // req -> idol (每个 req 可以分配给任意偶像, cap = 1)
    for (int j = 1; j <= M; ++j) {
        for (int k = 0; k < B[j]; ++k) {
            int rnode = reqStart[j] + k;
            for (int i = 1; i <= N; ++i) {
                addEdge(rnode, idolStart + i - 1, 1, 0);
            }
        }
    }
    // idol -> sink (容量 = A[i])
    for (int i = 1; i <= N; ++i) {
        if (A[i] > 0) addEdge(idolStart + i - 1, t, A[i], 0);
    }

    long long mincut = mcmf();            // 这即是 cut 容量
    long long ans = SUMC - mincut;        // 最大兴奋值
    if (ans < 0) ans = 0;
    cout << ans << "\n";
    return 0;
}
