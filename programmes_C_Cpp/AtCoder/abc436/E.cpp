#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> p[i];
    vector<int> vis(n + 1, 0);
    int ans{};
    for (int i = 1; i <= n; ++ i) {
        if (vis[i]) continue;
        int cnt{}, cur = i;
        while (!vis[cur]) {
            vis[cur] = 1;
            cur = p[cur];
            cnt ++;
        }
        ans += cnt * (cnt - 1) / 2;
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