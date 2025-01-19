#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    int maxn{}, sum{};
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i], sum += a[i], maxn = max(maxn, a[i]);
    int ans{};
    auto check = [&](int x) {
        int len = (sum + x - 1) / x;
        len = max(maxn, len);
        return len * x - sum <= k;
    };
    for (int i = 1; i <= n; ++ i) if (check(i)) ans = i;
    cout << ans << "\n"; 
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}