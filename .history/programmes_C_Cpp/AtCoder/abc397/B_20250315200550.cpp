#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    string s; cin >> s;
    int ans{};
    for (int i = 0; i < s.size(); ++ i) {
        if (i & 1) {
            if (s[i] == 'i') s.insert(i, "o"), ans ++;
        } else {
            if (s[i] == 'o') s.insert(i, "i"), ans ++;
        }
    }
    if (s.size() & 1) ans ++;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}