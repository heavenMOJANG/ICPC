#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n;
    vector<int> p(n + 1), a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> p[i];
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    function<int(int)> findSet = [&](int x) {
        return f[x] == x ? x : f[x] = findSet(f[x]);
    };
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}