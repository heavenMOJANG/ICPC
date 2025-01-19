#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 3010;
void solve() {
    vector<int> v(10);
    for (int i = 0; i < 10; ++ i) cin >> v[i];
    int n, m; cin >> n >> m;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i] >> b[i];
    vector<int> dp1(N, -INF), dp2(N, -INF);
    dp1[0] = 0;
    for (int i = 1; i <= n; ++ i)
        for (int j = a[i]; j <= m; ++ j) dp1[j] = max(dp1[j], dp1[j - a[i]] + b[i]);
    auto calc = [&](int a, int b) {
        for (int i = 0; ~i; -- i) if (10 * b > a * i) return v[i];
        return 0ll;
    };
    dp2[0] = 0;
    for (int i = 1; i <= m; ++ i)
        for (int j = i; j <= m; ++ j) dp2[j] = max(dp2[j], dp2[j - i] + i * calc(i, dp1[i]));
    cout << dp2[m] << "\n";
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}