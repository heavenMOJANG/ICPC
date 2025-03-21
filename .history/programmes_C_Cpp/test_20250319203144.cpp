#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> post(n), in(n);
    for (auto && x : post) cin >> x;
    for (auto && x : in) cin >> x;
    map<int, int> mp;
    function<void(int, int, int, int)> dfs = [&](int rt, int p, int pl, int pr) {
        if (pl > pr) return;
        int i = pl;
        while (i < pr && in[i] != post[rt]) i ++;
        mp[p] = post[rt];
        dfs(rt - 1 - pr + i, 2 * p + 1, pl, i - 1);
        dfs(rt - 1, 2 * p + 2, i + 1, pr);
    };
    dfs(n - 1, 0, 0, n - 1);
    vector<int> ans;
    for (auto [x, y] : mp) ans.emplace_back(y);
    for (int i = 0; i < ans.size(); ++ i) cout << ans[i] << " \n"[i == ans.size() - 1];
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}