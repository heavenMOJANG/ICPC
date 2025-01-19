#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
class DSU {
private:
    int n, siz;
    vector<int> father;
};
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), Lmax(n + 1, 0);
    for (int i = 1; i <= n; ++ i) cin >> a[i], Lmax[i] = max(Lmax[i - 1], a[i]);
    vector<int> ans(n + 1, 0);
    ans[n] = Lmax[n];
    int cur = n;
    for (int i = n - 1; i >= 1; -- i) {
        ans[i] = Lmax[i];
        while (Lmax[i] <= a[cur] && cur > i) cur --;
        if (Lmax[i] > a[cur]) ans[i] = max(ans[i], ans[cur]);
    }
    for (int i = 1; i <= n; ++ i) cout << ans[i] << " \n"[i == n];
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}