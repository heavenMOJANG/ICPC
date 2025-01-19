#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), pre(n + 1, 0);
    vector<vector<int>> d(30, vector<int>(2, 0));
    for (int i = 1; i <= n; ++ i) cin >> a[i], pre[i] = pre[i - 1] ^ a[i];
    for (int i = 0; i <= n; ++ i)
        for (int j = 30; j >= 0; -- j)
            d[j][(pre[i] >> j) & 1] ++;
    int sum = 0;
    for (int i = 0; i <= 30; ++ i) sum += d[i][0] * d[i][0] * (1ll << i);
    cout << sum << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}