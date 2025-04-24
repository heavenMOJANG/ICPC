#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    queue<int> q[n + 1];
    vector<int> cnt(m + 1, 0);
    for (int i = 1; i <= m; ++ i) {
        int k; cin >> k;
        for (int j{}; j < k; ++ j) {
            int x; cin >> x;
            q[x].push(i);
            cnt[i] ++;
        }
    }
    for (int i = 1; i <= n; ++ i) {
        int b; cin >> b;
        while (!q[b].empty()) {
            
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