#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    for (int i = 1; i <= n; ++ i) cin >> b[i];
    for (int i = 1; i <= n; ++ i) cin >> c[i];
    vector<int> pa(n + 1, 0), pb(n + 1, 0), pc(n + 1, 0);
    for (int i = 1; i <= n; ++ i) {
        pa[i] = pa[i - 1] + a[i];
        pb[i] = pb[i - 1] + b[i];
        pc[i] = pc[i - 1] + c[i];
    }
    vector<int> maxn(n + 1);
    maxn[1] = pa[1] - pb[1];
    for (int i = 2; i <= n; ++ i) maxn[i] = max(maxn[i - 1], pa[i] - pb[i]);
    int ans{};
    for (int i = 2; i < n; ++ i) {
        int tmp = maxn[i - 1] + pb[i] + pc[n] - pc[i];
        ans = max(ans, tmp);
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}