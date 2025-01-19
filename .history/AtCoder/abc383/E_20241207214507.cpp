#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e5 + 10;
class DSU {
public:
    DSU(int n) : fa(n), rk(n, 0) {
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
    vector<tuple<int, int, int>> e(m);
    for (int i = 0, u, v, w; i < m; ++ i) {
        cin >> u >> v >> w;
        u --, v --;
        e[i] = {w, u, v};
    }
    sort(e.begin(), e.end());
    vector<int> a(k), b(k);
    for (int i = 0; i < k; ++ i) cin >> a[i];
    for (int i = 0; i < k; ++ i) cin >> b[i];
    int ans{};
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}