#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    set<int> s;
    for (int i{}; i < n; ++ i) {
        int l, ans{}; cin >> l;
        for (int j{}; j < l; ++ j) {
            int x; cin >> x;
            if (!ans && s.count(x)) ans = x, s.erase(x);
        }
        cout << ans << "\n";
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}