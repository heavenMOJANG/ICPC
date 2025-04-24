#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n), vis(n, 0);
    int cnt{};
    for (int i{}; i < n; ++ i) {
        cin >> a[i];
        if (a[i] == i) vis[i] = 1;
    }
    int ans{};
    for (int i{}; i < n; ++ i) {
        if (vis[a[i]]) continue;
        int cnt{}, ok{};
        int tmp = a[i];
        while (1) {
            if (vis[tmp]) break;
            if (tmp == 0) ok = 1;
            cnt ++;
            vis[tmp] = 1;
            tmp = a[tmp];
        }
        if (ok) ans += cnt - 1;
        else ans += cnt + 1;
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