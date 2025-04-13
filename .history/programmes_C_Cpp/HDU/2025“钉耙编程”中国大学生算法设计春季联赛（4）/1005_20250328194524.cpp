#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int P, n, k; cin >> P >> n >> k;
    vector<int> v[2];
    for (int i = 1; i <= n; ++ i) {
        int t, p; cin >> t >> p;
        v[t].emplace_back(p);
    }
    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}