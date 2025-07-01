#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> c(2 * n);
    for (int i{}; i < n; ++ i) cin >> c[i], c[i + n] = c[i];
    unordered_set<int> s[2 * n];
    for (int i{}; i < m; ++ i) {
        int k; cin >> k;
        for (int j{}; j < k; ++ j) {
            int x; cin >> x;
            s[x].insert(i);
            s[x + n].insert(i);
        }
    }
    for (int i{}; i < (1ll << (2 * n)); ++ i) {
        int res{};
        vector<int> cnt(m, 0);
        for (int j{}; j < 2 * n; ++ j)
            if ((1ll << j) & i) {
                res += c[j];
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