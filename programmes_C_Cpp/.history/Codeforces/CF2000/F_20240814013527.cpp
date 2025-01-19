#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    vector<int> dp(k + 1, 1e9);
    dp[0] = 0;
    for (int i = 0; i < n; ++ i) {
        auto ndp = dp;
        int x, y; cin >> x >> y;
        for (int j = 0; j <= k; ++ j)
            ndp[min(j + x + y, k)] = min(ndp[min(j + x + y, k)], dp[j] + x * y);
        int sum = 0, cnt = 0;
        while (x > 1 || y > 1) {
            if (x < y) swap(x, y);
            cnt ++;
            sum += y;
            x --;
            for (int j = 0; j <= k; ++ j) ndp[min(j + cnt, k)] = min(ndp[min(j + cnt, k)], dp[j] + sum);
        }
    }
    cout << res << "\n";
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}