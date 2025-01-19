#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> f(n + 1), rk (n + 1), dep(n + 1);
    for (int i = 1;i <= n; ++ i) f[i] = i;
    function<int(int)> find = [&](int x) {
        return f[x] == x ? f[x] : f[x] = find(f[x]);
    };
    function<void(int, int)> merge = [&](int x,int y) {
        f[y] = x;
        dep[x] = max(dep[x], dep[y] + 1);
    };
    vector<int> ans;
    for (int i = 1, a, b, c; i < n; ++ i) {
        cin >> a >> b >> c;
        merge(a, b);
        ans.emplace_back(dep[c]);
    }
    for (int i = 0; i < n - 1; ++ i) cout << ans[i] << " \n"[i == n - 2];
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}