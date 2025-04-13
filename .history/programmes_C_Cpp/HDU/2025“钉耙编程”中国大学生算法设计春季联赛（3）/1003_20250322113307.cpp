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
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq[m + 1];
    queue<int> q;
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= m; ++ j) {
            cin >> c[i][j];
            if (a[j] < c[i][j]) req[i] ++, pq[j].push({});
        }
        for (int j = 1; j <= m; ++ j) cin >> w[i][j];
        if (!req[i]) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int j = 1; j <= m; ++ j) a[j] += w[u][j];
        while (!pq.empty()) {
            auto [r, id] = pq.top(); pq.pop();
            req[id] = 0;
            for (int j = 1; j <= m; ++ j) if (a[j] < c[id][j]) req[id] ++;
            if (!req[id]) q.push(id);
            else tmp.push({req[id], id});
        }
        pq = tmp;
    }
    if (!pq.empty()) cout << "NO\n";
    else cout << "YES\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}