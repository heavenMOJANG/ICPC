#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), pre(n + 1, 0), cnt(2, 0);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    int ans = 0;
    for (int i = 0; i <= 27; ++ i) {
        for (int j = 1; j <= n; ++ j)
            if ((a[j] >> i) & 1) pre[j] = pre[j - 1] ^ 1;
            else pre[j] = pre[j - 1];
        cnt[0] = cnt[1] = 0;
        for (int j = 0; j <= n; ++ j) cnt[pre[i]] ++;
        ans += (1ll << i) * cnt[0] * cnt[1];
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}