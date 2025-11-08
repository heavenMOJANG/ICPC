#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 510; // N_idols + 2*M_songs + 2 is enough
constexpr int M = 25000; // Edge count: N + M*N + M + M is roughly 100+10000+100+100
struct Edge { int to, nxt, cap, cst; } e[M];
// Renamed n to N_idols, k to M_songs to match problem statement
int N_idols, M_songs;
int dis[N], cur[N], head[N], idx, s, t, ret, inq[N];
void addEdge(int u, int v, int cap, int cst) {
    e[idx] = {v, head[u], cap, cst}, head[u] = idx ++;
    e[idx] = {u, head[v], 0, -cst}, head[v] = idx ++;
}
bool spfa() {
    fill(dis, dis + N, INF);
    memcpy(cur, head, sizeof(head));
    queue<int> q;
    q.push(s), dis[s] = 0, inq[s] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        inq[u] = 0;
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
int dfs(int u = s, int flow = INF) {
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
    int res{};
    while (spfa()) {
        int x;
        while ((x = dfs())) res += x;
    }
    return res;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    fill(head, head + N, -1);
    cin >> N_idols >> M_songs;
    vector<int> A(N_idols + 1);
    for (int i = 1; i <= N_idols; ++i) cin >> A[i];
    vector<pair<int, int>> songs(M_songs + 1);
    for (int i = 1; i <= M_songs; ++i) cin >> songs[i].first >> songs[i].second;

    s = 0;
    t = N_idols + 2 * M_songs + 1;

    // Type 1: Edges from source to idols
    for (int i = 1; i <= N_idols; ++i) {
        addEdge(s, i, A[i], 0);
    }

    for (int j = 1; j <= M_songs; ++j) {
        int node_perf = N_idols + j;
        int node_choice = N_idols + M_songs + j;
        int B_j = songs[j].first;
        int C_j = songs[j].second;

        // Type 2: Edges from idols to song performances
        for (int i = 1; i <= N_idols; ++i) {
            addEdge(i, node_perf, 1, 0);
        }

        // Type 3: Edges from song performances to song choices
        addEdge(node_perf, node_choice, B_j, 0);

        // Type 4: Edges from song choices to sink
        addEdge(node_choice, t, 1, -C_j);
    }

    mcmf();
    cout << -ret << "\n";
    return 0;
}