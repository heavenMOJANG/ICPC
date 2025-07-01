#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> cnt(110, 0), a(n + 1);
    for (int i = 1; i <= n; ++ i) {
        cin >> a[i];
        cnt[a[i]] ++;
    }
    int ans{};
    for (int i = 1; i <= m; ++ i) if (cnt[i] == 0) { cout << "0\n"; return; }
    for (int i = n; i >= 1; -- i) {
        cnt[a[i]] --;
        ans ++;
        if (cnt[a[i]] == 0 && 1 <= a[i] && a[i] <= m) break;
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}