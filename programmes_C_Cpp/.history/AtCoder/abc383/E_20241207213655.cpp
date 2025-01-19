#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e5 + 10;
struct Edge {
    int u, v, w;
    bool operator < (const Edge & x) const { return w < x.w; }
}e[N];
class DSU {
public:
    DSU(int n) : fa(n + 1), rk(n + 1, 0) {
        iota(fa.begin(), fa.end(), 0);
    }
    int findSet(int x) { return fa[x] == x ? x : fa[x] = findSet(fa[x]); }
    bool unionSet(int x, int y) {
        x = findSet(x), y = findSet(y);
        if (x != y) {
            if (rk[x] > rk[y]) fa[y] = x;
            else if (rk[x] < rk[y]) fa[x] = y;
            else fa[y] = x, rk[x] ++;
        } return false;
    }
private:
    vector<int> fa, rk;
};
void solve() {
    int n, m, k; cin >> n >> m >> k;
    int l{}, r{};
    for (int i = 0; i < m; ++ i) cin >> e[i].u >> e[i].v >> e[i].w;
    sort(e + 0, e + m);
    vector<int> a(k), b(k);
    for (int i = 0; i < k; ++ i) cin >> a[i];
    for (int i = 0; i < k; ++ i) cin >> b[i];
    int l = 0, r =
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}