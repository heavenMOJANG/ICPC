#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n + 1, 0);
    for (int i = 0, x; i < m; ++ i) cin >> x, a[x] = 1;
    vector<int> ans;
    for (int i = 1; i <= n; ++ i) if (!a[i]) ans.emplace_back(i);
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++ i) cout << ans[i] << " \n"[i == ans.size() - 1];
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}