#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 20010;
constexpr int M = 2000010;
struct Edge { int to, nxt, cap, cst; } e[M];
int head[N], idx;
int dis[N], cur[N], inq[N];
int n, m, s, t, ret;
int A[110], B[110], C[110];
void addEdge(int u, int v, int cap, int cst) {
    e[idx] = {v, head[u], cap, cst}; head[u] = idx++;
    e[idx] = {u, head[v], 0, -cst}; head[v] = idx++;
}
bool spfa() {
    fill(dis, dis + N, INF);
    memcpy(cur, head, sizeof(head));
    queue<int> q;
    q.push(s); dis[s] = 0; inq[s] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop(); inq[u] = 0;
        for (int i = head[u]; ~i; i = e[i].nxt) {
            int v = e[i].to;
            if (e[i].cap && dis[v] > dis[u] + e[i].cst) {
                dis[v] = dis[u] + e[i].cst;
                if (!inq[v]) q.push(v), inq[v] = 1;
            }
        }
    }
    return dis[t] != INF;
}
int dfs(int u, int flow = INF) {
    if (u == t) return flow;
    inq[u] = 1;
    int used = 0;
    for (int &i = cur[u]; ~i && used < flow; i = e[i].nxt) {
        int v = e[i].to;
        if (!inq[v] && e[i].cap && dis[v] == dis[u] + e[i].cst) {
            int c = dfs(v, min(flow - used, e[i].cap));
            ret += c * e[i].cst;
            e[i].cap -= c;
            e[i ^ 1].cap += c;
            used += c;
        }
    }
    inq[u] = 0;
    return used;
}
int mcmf() {
    int res = 0;
    while (spfa()) {
        int x;
        while ((x = dfs(s))) res += x;
    }
    return res;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    fill(head, head + N, -1);
    cin >> n >> m;  // n = N偶像数, m = M歌曲数
    for (int i = 1; i <= n; ++i) cin >> A[i];
    for (int j = 1; j <= m; ++j) {
        cin >> B[j] >> C[j];
    }
    s = 0;
    int songStart = 1;
    int curNode = songStart + m; // req节点开始编号
    vector<int> reqStart(m + 1);
    for (int j = 1; j <= m; ++j) {
        reqStart[j] = curNode;
        curNode += B[j];
    }
    int idolStart = curNode;
    curNode += n;
    t = curNode;
    long long SUMC = 0;
    for (int j = 1; j <= m; ++j) SUMC += C[j];

    // source -> song
    for (int j = 1; j <= m; ++j) addEdge(s, songStart + j - 1, C[j], 0);

    // song -> req
    for (int j = 1; j <= m; ++j)
        for (int k = 0; k < B[j]; ++k)
            addEdge(songStart + j - 1, reqStart[j] + k, INF, 0);

    // req -> idol (每个req可以分配给任意偶像，容量1)
    for (int j = 1; j <= m; ++j)
        for (int k = 0; k < B[j]; ++k)
            for (int i = 1; i <= n; ++i)
                addEdge(reqStart[j] + k, idolStart + i - 1, 1, 0);

    // idol -> sink
    for (int i = 1; i <= n; ++i) addEdge(idolStart + i - 1, t, A[i], 0);

    mcmf();
    cout << SUMC - ret << "\n";  // 最大可能的兴奋值
    return 0;
}
