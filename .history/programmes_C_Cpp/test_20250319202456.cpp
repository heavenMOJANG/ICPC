#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> post(100);
    for (int i = 1; i <= n; ++ i) cin >> post[i];
    vector<int> ans(100);
    int p = 1;
    function<void(int)> dfs = [&](int x) {
        if (x > n) return;
        dfs(x << 1);
        dfs(x << 1 | 1);
        ans[x] = 
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}