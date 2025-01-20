#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    set<int> s[64];
    vector<int> w(n);
    for (int i = 0; i < n; ++ i) {
        cin >> w[i];
        for (int j = 0; j < 64; ++ j) if (w[i] & (1ll << j)) s[j].insert(i);
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}