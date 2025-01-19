#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    int r = n % k;
    if (!r) r = k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    auto check = [&](int  x) {
        vector<int> res(r + 1, -INF);
        res[0] = 0;
        for (int i = 1; i <= n; ++ i) {
            int id = (i - 1) % k + 1;
            if (id <= r) res[id] = max(res[id], dp[id - 1] + (a[i] >= x ? 1 : -1));
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