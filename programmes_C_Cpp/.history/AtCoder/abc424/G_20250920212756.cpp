#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int NODE_MAX = 42000;    // 节点上界（调整为安全值）
constexpr int EDGE_MAX = 4200000;  // 边上界（双向计数）
struct Edge { int to, nxt, cap, cst; } e[EDGE_MAX];
int head[NODE_MAX], idx;
int dis[NODE_MAX], cur[NODE_MAX], inq[NODE_MAX];
int s, t;
const long long CAP_INF = (1LL<<60);

void addEdge(int u, int v, int cap, int cst) {
    e[idx] = {v, head[u], (int)cap, cst}; head[u] = idx++;
    e[idx] = {u, head[v], 0, -cst}; head[v] = idx++;
}

// BFS 构建分层图（保留函数名 spfa）
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

// Dinic 的 DFS（保留函数名 dfs）
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

long long mcmf() {
    long long flow = 0;
    while (spfa()) {
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
    if (!(cin >> N >> M)) return 0;
    vector<int> A(N+1);
    for (int i = 1; i <= N; ++i) cin >> A[i];
    vector<int> B(M+1);
    vector<long long> C(M+1);
    long long SUMC = 0;
    for (int j = 1; j <= M; ++j) {
        cin >> B[j] >> C[j];
        SUMC += C[j];
    }

    // 编号布局（尽量和你之前一致）
    s = 0;
    int songStart = 1;              // songs: songStart .. songStart+M-1
    int curNode = songStart + M;    // next free
    vector<int> reqStart(M+1);      // req tokens: for each song j, B[j] tokens
    for (int j = 1; j <= M; ++j) {
        reqStart[j] = curNode;
        curNode += B[j];
    }
    int pairStart = curNode;        // pair nodes: for each (j,i) one node, total M*N
    curNode += M * N;
    int idolStart = curNode;        // idols: idolStart .. idolStart+N-1
    curNode += N;
    t = curNode;
    curNode += 1;

    if (t + 5 >= NODE_MAX) {
        cerr << "Error: NODE_MAX too small\n";
        return 0;
    }

    // source -> song (容量 = C[j])
    for (int j = 1; j <= M; ++j) {
        if (C[j] > 0) addEdge(s, songStart + j - 1, (int)C[j], 0);
    }

    // song -> req (每个 token，用 INF 连接，使 token 必须与 song 同侧)
    for (int j = 1; j <= M; ++j) {
        for (int k = 0; k < B[j]; ++k) {
            addEdge(songStart + j - 1, reqStart[j] + k, (int)CAP_INF, 0);
        }
    }

    // req -> pair(j,i) （每个 token 可尝试分配给所有偶像，通过 pair 节点再流向偶像）
    // pair(j,i) -> idol_i 容量 1，保证同一歌同一偶像至多被使用一次
    for (int j = 1; j <= M; ++j) {
        for (int k = 0; k < B[j]; ++k) {
            int rnode = reqStart[j] + k;
            for (int i = 1; i <= N; ++i) {
                int pnode = pairStart + (j - 1) * N + (i - 1);
                addEdge(rnode, pnode, 1, 0);      // token -> pair
            }
        }
    }
    // pair -> idol (cap 1)
    for (int j = 1; j <= M; ++j) {
        for (int i = 1; i <= N; ++i) {
            int pnode = pairStart + (j - 1) * N + (i - 1);
            int inode = idolStart + i - 1;
            addEdge(pnode, inode, 1, 0);
        }
    }

    // idol -> sink (容量 = A[i])
    for (int i = 1; i <= N; ++i) {
        if (A[i] > 0) addEdge(idolStart + i - 1, t, A[i], 0);
    }

    long long mincut = mcmf();
    long long ans = SUMC - mincut;
    if (ans < 0) ans = 0;
    cout << ans << "\n";
    return 0;
}
