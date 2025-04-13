#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(m + 1);
    for (int i = 1; i <= m; ++ i) cin >> a[i];
    vector c(n + 1, vector<int> (m + 1)), w = c;
    vector<int> req(n + 1, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    queue<int> q;
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= m; ++ j) {
            cin >> c[i][j];
            if (a[j] < c[i][j]) req[i] ++;
        }
        for (int j = 1; j <= m; ++ j) cin >> w[i][j];
        if (!req[i]) q.push(i); else pq.push({req[i], i});
    }
    while (!q.empty()) {
        
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}