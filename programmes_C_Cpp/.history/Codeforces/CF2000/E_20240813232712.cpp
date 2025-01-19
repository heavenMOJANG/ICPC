#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m, k, w; cin >> n >> m >> k >> w;
    vector g(n + 1, vector<int>(m + 1, 0));
    vector<int> a(w);
    for (auto && x : a) cin >> x;
    /*
    sort(a.begin(), a.end());
    for (int i = 1; i + k - 1 <= n; ++ i)
        for (int j = 1; j + k - 1 <= m; ++ j) {
            g[i][j] ++; g[i][j + k] --;
            g[i + k][j] --; g[i + k][j + k] ++;
        }
    priority_queue<int> pq;
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j) {
            g[i][j] += g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
            pq.push(g[i][j]);
        }
    int ans = 0;
    for (int i = w - 1; i >= 0; -- i) {
        ans += a[i] * pq.top(); pq.pop();
    }
    cout << ans << "\n";
    */
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}