#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
class DSU {
private:
    vector<int> f, siz;
public:
    DSU(int n) : f(n + 1, 0), siz(n + 1, 1) { iota(f.begin(), f.end(), 0); }
    int findSet(int x) { return f[x] == x ? x : f[x] = findSet(f[x]); }
    void unionSet(int x, int y) {
        x = findSet(x), y = findSet(y);
        if (x == y) return;
        if (siz[x] >= siz[y]) f[y] = x, siz[x] += siz[y];
        else f[x] = y, siz[y] += siz[x];
    }
    int getF(int x) { return f[x]; }
};
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int n, m;
    while (cin >> n >> m && n) {
        DSU dsu(n);
        while (m --) {
            int u, v; cin >> u >> v;
            dsu.unionSet(u, v);
        }
        int ans{};
        for (int i = 1; i <= n; ++ i) if (dsu.getF(i) == i) ans ++;
        cout << ans - 1 << "\n";
    }
    return 0;
}