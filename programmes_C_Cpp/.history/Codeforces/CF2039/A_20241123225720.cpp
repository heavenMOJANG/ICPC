#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
int n, cnt[101];
int ans[51], vis[101];
void dfs(int x) {
    if (x == n + 1) {
        for (int i = 1; i <= n; ++ i) cout << ans[i] << " \n"[i == n];
        return;
    }
    for (int i = 1; i <= 100; ++ i) {
        if (!cnt[i % x] && !vis[i]) {
            vis[i] = 1;
            cnt[i % x] = 1;
            ans[x] = i;
            dfs(x + 1);
            vis[i] = 0;
            cnt[i % x] = 0;
        }
    }
}
void solve() {
    cin >> n;
    dfs(n);
    cout << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}