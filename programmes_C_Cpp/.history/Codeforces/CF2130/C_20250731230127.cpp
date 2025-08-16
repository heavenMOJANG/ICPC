#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    struct DSU {
        vector<int> p;
        DSU(int n) : p(n + 1) { iota(p.begin(), p.end(), 0); }
        int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
        bool merge(int x, int y) {
            x = find(x), y = find(y);
            if (x == y) return false;
            if (p[x] > p[y]) swap(p[x], p[y]);
            p[x] += p[y];
            p[y] = x;
            return true;
        }
    };
    int n; cin >> n;
    vector<tuple<int, int, int, int>> e;
    for (int i{}; i < n; ++ i) {
        int a, b; cin >> a >> b;
        e.emplace_back(b - a, a, b, i + 1);
    }
    sort(e.begin(), e.end(), [](auto& x, auto& y) {return get<0>(x) > get<0>(y); });
    DSU dsu(2 * n + 10)
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}