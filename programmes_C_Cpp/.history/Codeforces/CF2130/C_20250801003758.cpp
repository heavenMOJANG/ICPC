#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    struct DSU {
        vector<int> p, rk;
        DSU(int n) : p(n + 1), rk (n + 1, 0) { iota(p.begin(), p.end(), 0); }
        int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
        bool merge(int x, int y) {
            x = find(x), y = find(y);
            if (x == y) return false;
            if (rk[x] < rk[y]) swap(x, y);
            p[y] = x;
            if (rk[x] == rk[y]) rk[x] ++;
            return true;
        }
    };
    struct
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