#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m, k; cin >> n >> m >> k;
    string s; cin >> s;
    int len = s[0] == '0', ans{};
    for (int i = 1; i < s.size(); ++ i) {
        if (s[i] == '0') len ++;
        else {
            if (len >= m) {
                int d = m - 1 + k;
                ans += (len + d - 1) / d;
            }
            else len = 0;
        }
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