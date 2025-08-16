#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    struct DSU {
        vector<int> p, minv, maxv;
        DSU(int n) : p(n + 1), minv(n + 1, 0), maxv(n + 1, 0) { iota(p.begin(), p.end(), 0); }
        int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
        void merge(int x, int y) {
            x = find(x), y = find(y);
            if (x == y) return;
            if (x > y) swap(x, y);
            p[y] = x;
            minv[x] = min(minv[x], minv[y]);
            maxv[x] = max(maxv[x], minv[y]);
        }
    };
    int n; cin >> n;
    int maxv{};
    vector<tuple<int, int, int>> e;
    for (int i{}; i < n; ++ i) {
        int a, b; cin >> a >> b;
        maxv = max(maxv, b);
        e.emplace_back(a, b, i + 1); 
    }
    int scr{};
    DSU dsu(2 * n + 10);
    vector<int> f(2 * n + 10), ans;
    for (auto [len, a, b, id]: e) {
        if (dsu.find(a) == dsu.find(b)) continue;
        int cnt{};
        for (int i = a; i < b; ++ i) if (!f[i]) cnt ++;
        if (!cnt) continue;
        fill(f.begin() + a, f.begin() + b, 1);
        dsu.merge(a, b);
        ans.emplace_back(id);
    }
    cout << ans.size() << "\n";
    for (int i{}; i < ans.size(); ++ i) cout << ans[i] << " \n"[i == ans.size() - 1];
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}