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
struct Query {
    int u, v, w;
    bool operator < (const Query& b) const { return w > b.w; }
}
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
    int nn = n;
    DSU dsu(n + q);
    vector<Edge> e;
    int ok = 1, cnt{};
    while (q --) {
        int op; cin >> op;
        if (op == 1) {
            int a, b; cin >> a >> b;
            nn ++;
            e.emplace_back(a, b);
            dsu.fa.emplace_back(nn);
            
        }
        if (op == 2) {

        }
        if (op == 3) {

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