#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 2'000'000'000'000'000LL;  // 足够大，> 500 * 1e9 * 2

constexpr int MAXN = 510;
static ll dis[MAXN][MAXN];

inline void addEdge(int n, int u, int v, ll w) {
    // 插入新边 u<->v，权重 w
    if (dis[u][v] > w) {
        dis[u][v] = dis[v][u] = w;
        // O(n^2) 动态 APSP 更新
        for (int i = 0; i <= n; ++i) {
            ll diu = dis[i][u], div = dis[i][v];
            if (diu == INF && div == INF) continue;
            for (int j = 0; j <= n; ++j) {
                ll p1 = (diu < INF && dis[v][j] < INF ? diu + w + dis[v][j] : INF);
                ll p2 = (div < INF && dis[u][j] < INF ? div + w + dis[u][j] : INF);
                ll mn = min(dis[i][j], min(p1, p2));
                if (mn < dis[i][j]) {
                    dis[i][j] = mn;
                }
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    // 0..n；0不用于城市，但机场逻辑里也不连虚节点
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            dis[i][j] = (i == j ? 0 : INF);
        }
    }
    // 读初始道路
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        dis[u][v] = dis[v][u] = min(dis[u][v], w);
    }
    // 初次 Floyd–Warshall 只算道路
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            if (dis[i][k] == INF) continue;
            for (int j = 1; j <= n; ++j) {
                ll via = dis[i][k] + dis[k][j];
                if (via < dis[i][j]) {
                    dis[i][j] = via;
                }
            }
        }
    }

    // 读初始机场集和飞行时间 T
    int K;
    ll T;
    cin >> K >> T;
    vector<int> airports;
    airports.reserve(n);
    for (int i = 0; i < K; ++i) {
        int x;
        cin >> x;
        // 把初始机场和已有机场两两连边
        for (int y : airports) {
            addEdge(n, x, y, T);
        }
        airports.push_back(x);
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int u, v;
            ll w;
            cin >> u >> v >> w;
            addEdge(n, u, v, w);
        }
        else if (op == 2) {
            int x;
            cin >> x;
            // 新机场 x，与所有已有机场连航线
            for (int y : airports) {
                addEdge(n, x, y, T);
            }
            airports.push_back(x);
        }
        else if (op == 3) {
            ll ans = 0;
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (dis[i][j] < INF) ans += dis[i][j];
                }
            }
            cout << ans << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
