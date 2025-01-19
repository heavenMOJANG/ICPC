#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
int n, m, idx;
vector<int> a(20);
vector<vector<int>> ans(300000);
void dfs(int x) {
    if (x == n + 1) {
        ans[++ idx] = a;
        for (int i = 1; i <= n; ++ i) cout << a[i] << " \n"[i == n];
        return;
    }
    for (int i = a[x - 1] + 10; i <= m - (n - x) * 10; ++ i) {
        a[x] = i;
        dfs(x + 1);
    }
}
void solve() {
    cin >> n >> m;
    a[0] = -9;
    dfs(1);
    cout << cnt << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}