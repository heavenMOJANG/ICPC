#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    vector<int> d(4 * k + 1);
    int maxn = 0;
    for (int i = 1, x; i <= n; ++ i) {
        cin >> x;
        maxn = max(maxn, x);
        x = (x - 1) % (2 * k) + 1;
        d[x] ++;
        d[x + k] --;
    }
    for (int i = 1; i <= 4 * k; ++ i) {
        d[i] += d[i - 1];
        if (i > 2 * k) d[i - 2 * k] += d[i];
    }
    int ans = INF;
    for (int i = 1; i <= 2 * k; ++ i)
        if (d[i] >= n) ans = min(ans, i + max(0ll, (maxn - i + 2 * k - 1) / (2 * k) * 2 * k));
    if (ans == INF) cout << "-1\n";
    else cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}