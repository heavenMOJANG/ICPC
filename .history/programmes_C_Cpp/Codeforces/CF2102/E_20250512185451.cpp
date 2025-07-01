#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    set<int> s;
    vector dp(n + 1, vector<int> (2));
    for (int j{}; j < 2; ++ j) {
        s.clear();
        for (int i = 1; i <= n; ++ i) s.insert(i);
        for (int i = (j ? n : 1ll); (j ? i > 1 : i < n); (j ? -- i: ++ i)) {
            auto it = s.upper_bound(a[i]);
            if (it != s.begin()) s.erase(*(-- it));
            dp[i][j] = n - s.size();
        }
    }
    int ans{};
    for (int i = 1; i < n; ++ i) ans += min(dp[i][0], dp[i + 1][1]);
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}