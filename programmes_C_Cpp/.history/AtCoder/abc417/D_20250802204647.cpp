#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 4e18;
void solve() {
    int n; cin >> n;
    vector<int> p(n), a(n), b(n);
    for (int i{}; i < n; ++ i) cin >> p[i] >> a[i] >> b[i];
    map<int, pair<int, int>> mp;
    mp[0] = {1, 0};
    for (int i{}; i < n; ++ i) {
        map<int, pair<int, int>> nxt;
        for (auto it = mp.begin(); it != mp.end(); ++ it) {
            int l = it -> first;
        }
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}