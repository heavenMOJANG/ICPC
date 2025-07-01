#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> c(n);
    for (int i{}; i < n; ++ i) cin >> c[i];
    unordered_set<int> s[n];
    for (int i{}; i < m; ++ i) {
        int k; cin >> k;
        for (int j{}; j < k; ++ j) {
            int x; cin >> x;
            s[x - 1].insert(i);
        }
    }
    int minn = LLONG_MAX;
    vector<int> cnt(m, 0);
    auto dfs = [&](auto dfs, int x) {
        if (x == n) {

        }
    };
    cout << minn << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}