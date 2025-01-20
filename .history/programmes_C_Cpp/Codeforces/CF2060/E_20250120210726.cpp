#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
class DSU {
private:
public:
    vector<int> f, siz;
    DSU (int len) : f(len + 1), siz(len + 1, 1) { iota(f.begin(), f.end(), 0); }
    int findSet(int x) { return f[x] == x ? x : f[x] = findSet(f[x]); }
    void unionSet(int x, int y) {
        x = findSet(x), y = findSet(y);
        if (x == y) return;
        if (siz[x] >= siz[y]) f[y] = x, siz[x] += siz[y];
        else f[x] = y, siz[y] += siz[x];
    }
    bool isSame(int x, int y) { return findSet(x) == findSet(y); }
};
void solve() {
    int n, m1, m2; cin >> n >> m1 >> m2;
    vector<pair<int, int>> a(m1);
    DSU F(n), G(n);
    for (int i = 0; i < m1; ++ i) {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 0; i < m2; ++ i) {
        int u, v; cin >> u >> v;
        G.unionSet(u, v);
    }
    int ans{};
    for (int i = 0; i < m1; ++ i)
        if (!G.isSame(a[i].first, a[i].second)) ans ++;
        else F.unionSet(a[i].first, a[i].second);
    int cntf{}, cntg{};
    for (int i = 1; i <= n; ++ i) {
        cntf += F.findSet(i) == i;
        cntg += G.findSet(i) == i;
    }
    ans += cntg - cntf;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}