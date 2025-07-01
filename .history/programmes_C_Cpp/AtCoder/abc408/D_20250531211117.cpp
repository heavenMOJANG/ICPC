#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int cnt{}, res{}, maxn{};
    for (int i{}; i < n; ++ i) {
        if (s[i] == '1') {
            cnt ++;
            res = res > 0 ? res + 1 : 1ll;
        } else res = res > 0 ? res - 1 : - 1ll;
        maxn = max(maxn, res);
    }
    cout << cnt - maxn << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}