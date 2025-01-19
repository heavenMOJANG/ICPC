#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    s = " " + s;
    vector<int> ans(n + 1, 0);
    for (int i = 1; i <= n; ++ i) ans[i] = ans[i - 1] + (s[i] - '0') * i;
    int r{};
    for (int i = n; i >= 1; -- i) {
        ans[i] += r;
        r = ans[i] / 10;
        ans[i] %= 10;
    }
    if (r) cout << r;
    for (int i = 1; i <= n; ++ i) cout << ans[i];
    cout << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}