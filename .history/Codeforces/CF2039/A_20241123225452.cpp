#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
int n, vis[51];
int ans[51], vis[51];
void dfs(int x) {
    if (x == n + 1) {
        for (int i = 1; i <= n; ++ i) cout << ans[i] << " \n"[i == n];
        return;
    }
    for (int i = 1; i <= 100; ++ i) {
        
    }
}
void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++ i) cout << (10 + i) % i << " \n"[i == n];
    cout << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}