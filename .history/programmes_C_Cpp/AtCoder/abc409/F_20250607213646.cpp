#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct Point { int x, y; };
struct Edge {
    int u, v, w;
    bool operator < (const Edge& b) const { return w < b.w; }
};
struct DSU {
    vector<int> fa;
    int scc{};
    DSU(int n) : fa(n + 1), scc(n) { iota(fa.begin(), fa.end(), 0); }
    int findSet(int x) { return fa[x] == x ? x : fa[x] = findSet(fa[x]); }
    void unionSet(int x, int y) {
        x = findSet(x), y = findSet(y);
        if (x == y) return;
        fa[x] = y;
        scc --;
    }
};
int getDis(const Point& a, const Point& b) { return abs(a.x - b.x) + abs(a.y - b.y); }
void solve() {
    int n, q; cin >> n >> q;
    vector<Point> p(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> p[i].x >> p[i].y;
    DSU dsu(n + q);
    int N = n;
    vector<Edge> e;
    int flag = 1, pt{};
    while (q --) {
        int op; cin >> op;
        if (op == 1) {
            int a, b; cin >> a >> b;
            N ++;
            e.emplace_back(a, b);
            dsu.fa.emplace_back(N);
            dsu.fa[N] = N;
            dsu.scc ++;
            flag = 1;
        }
        if (op == 2) {
            if (dsu.scc == 1) { cout << "-1\n"; continue; }
            if (flag) {
                e.clear();
                for (int i = 1; i <= N; ++ i)
                    for (int j = i + 1; j <= N; ++ j) e.emplace_back(i, j, getDis(p[i], p[j]));
                sort(e.begin(), e.end());
                flag = pt = 0;
            }
            int minn = -1ll, idx = -1ll;
            for (int i = pt; i < e.size(); ++ i) {
                auto [u, v, w] = e[i];
                if (dsu.findSet(u) != dsu.findSet(v)) {
                    minn = w;
                    idx = i;
                    break;
                }
            }
            cout << minn << "\n";
            if (minn == -1) continue;
            for (int i = idx; i < e.size(); ++ i) {
                auto [u, v, w] = e[i];
                if (w > minn) { pt = i; break; }
                if (w == minn) dsu.unionSet(u, v);
                if (i == e.size() - 1) pt = e.size();
            }
        }
        if (op == 3) {
            int u, v; cin >> u >> v;
            cout << (dsu.findSet(u) == dsu.findSet(v) ? "Yes\n" : "No\n");
        }
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}