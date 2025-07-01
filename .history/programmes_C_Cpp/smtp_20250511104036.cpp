#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(2 * n + 1, 0);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    vector<int> g[2 * n + 1], vis(2 * n + 1, 0);
    for (int i = 1; i <= n; ++ i)
        if (a[i] != i) {
            int cur = a[i];
            while (cur && !vis[cur]) {
                vis[cur] = 1;
                cur = a[cur];
                if (a[cur]) g[a[cur]].emplace_back(cur);
            }
        }
    for (int i = 1; i <= 2 * n; ++ i)
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}