#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
int n, m, a[20];
void dfs(int x) {
    if (x == n + 1) {
        for (int i = 1; i <= n; ++ i) cout << a[i] << " \n"[i == n];
        return;
    }
    for (int i = a[x - 1] + 1; i <= m - (n - x) * 10) {
        a[x] = 
        dfs(x + 1);
    }
}
void solve() {
    cin >> n >> m;
    dfs(1);
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}