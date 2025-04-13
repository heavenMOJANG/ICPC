#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int dx[] = {0, 1, 0, -1, 0, 2, 0, -2};
constexpr int dy[] = {1, 0, -1, 0, 2, 0, -2, 0};
void solve() {
    int n, m; cin >> n >> m;
    string g[n];
    for (int i{}; i < n; ++ i) cin >> g[i];
    vector<int> dis(n * m, INF), vis(n * m, 0);
    for (int i{}; i < n; ++ i)
        for (int j{}; j < m; ++ j) {
            for (int k{}; k < 8; ++ k) {
                
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