#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr int dx[4] = {1,-1,0,0};
constexpr int dy[4] = {0,0,1,-1};
constexpr int N = 2e6 + 10;
struct Edge {
    int to, nxt;
    ll cap, w;
} edge[N << 2];
int head[N], idx;
int S, T, n;
ll total{}, dis[N], mincost = 0;
int pv_v[N], pv_e[N];
bool inq[N];
void add_edge(int u, int v, ll f, ll c) {
    edge[++idx] = {v, head[u], f, c}; head[u] = idx;
    edge[++idx] = {u, head[v], 0, -c}; head[v] = idx;
}
bool spfa() {
    fill(dis+1, dis+1+n, INF);
    fill(inq+1, inq+1+n, false);
    queue<int> q;
    dis[S] = 0; q.push(S); inq[S] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop(); inq[u] = false;
        for (int e = head[u]; e; e = edge[e].nxt) {
            int v = edge[e].to;
            if (edge[e].cap > 0 && dis[u] + edge[e].w < dis[v]) {
                dis[v] = dis[u] + edge[e].w;
                pv_v[v] = u; pv_e[v] = e;
                if (!inq[v]) {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
    return dis[T] < INF;
}
void mcmf() {
    while (spfa()) {
        ll aug = LLONG_MAX;
        for (int v = T; v != S; v = pv_v[v])
            aug = min(aug, edge[pv_e[v]].cap);
        for (int v = T; v != S; v = pv_v[v]) {
            int e = pv_e[v];
            edge[e].cap -= aug;
            edge[e^1].cap += aug;
            mincost += aug * edge[e].w;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int H, W; cin >> H >> W;
    vector<vector<ll>> A(H, vector<ll>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
            total += A[i][j];
        }
    }
    S = H * W + 1;
    T = H * W + 2;
    n = T;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int u = i * W + j + 1;
            if ((i + j) % 2 == 0) {
                add_edge(S, u, 1, 0);
                for (int d = 0; d < 4; d++) {
                    int ni = i + dx[d], nj = j + dy[d];
                    if (ni >= 0 && ni < H && nj >= 0 && nj < W) {
                        ll sum = A[i][j] + A[ni][nj];
                        if (sum < 0) {
                            int v = ni * W + nj + 1;
                            add_edge(u, v, 1, sum);
                        }
                    }
                }
            } else add_edge(u, T, 1, 0);
        }
    }
    mcmf();
    cout << (total - mincost) << "\n";
    return 0;
}
