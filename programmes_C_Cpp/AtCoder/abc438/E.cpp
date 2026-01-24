#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    vector go(30, vector<int>(n + 1, 0)), sum = go;
    for (int i = 1; i <= n; ++ i) go[0][i] = a[i], sum[0][i] = i;
    for (int j = 1; j < 30; ++ j)
        for (int i = 1; i <= n; ++ i) {
            go[j][i] = go[j - 1][go[j - 1][i]];
            sum[j][i] = sum[j - 1][i] + sum[j - 1][go[j - 1][i]];
    }
    while (q --) {
        int t, b; cin >> t >> b;
        int cur = b, ans{};
        for (int j{}; j < 30; ++ j)
            if ((1ll << j) & t) {
                ans += sum[j][cur];
                cur = go[j][cur];
            }
        cout << ans << "\n";
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}