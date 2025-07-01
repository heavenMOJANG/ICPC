#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e6 + 10;
void solve() {
    int q; cin >> q;
    int ans{};
    unordered_set<string> se;
    while (q --) {
        string t, s; cin >> t >> s;
        if (t == "2") {
            
        } else {
            
        }
        cout << ans << "\n";
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}