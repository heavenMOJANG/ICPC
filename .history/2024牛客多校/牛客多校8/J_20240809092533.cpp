#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    if (m == n - 2) {cout << "-1\n"; return;}
    int l = 1, r = n - m;
    vector<int> ans(n);
    for (int i = n - m - 1; i >= 0; i -= 3) ans[i] = r --;
    for (int i = n - m - 2; i >= 0; i -= 3) ans[i] = r --;
    for (int i = n - m - 3; i >= 0; i -= 3) ans[i] = l ++;
    for (int i = n - m; i < n; ++ i) ans[i] = i + 1;
    for (int i = 0; i < n; ++ i) cout << ans[i] << " \n"[i == n - 1];
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}