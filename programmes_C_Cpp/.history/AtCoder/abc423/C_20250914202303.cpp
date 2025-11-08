#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, r; cin >> n >> r;
    vector<int> l(n + 1);
    int c0{};
    for (int i = 1; i <= n; ++ i) {
        cin >> l[i];
        if (!l[i]) c0 ++;
    }
    if (!c0) { cout << "0\n"; return; }
    vector<int> b(n + 1, 0);
    b[0] = 0;
    for (int i = 1; i <= n; ++ i) b[i] = b[i - 1] + (l[i] == 1);
    int s = b[r], minn = LLONG_MAX, maxn = LLONG_MIN;
    for (int i = 1; i <= n; ++ i)
        if (!l[i]) minn = min(minn, b[i - 1]), maxn = max(maxn, b[i - 1]);
    int ans = c0 + 2 * (max(maxn, s) - min(minn, s));
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}