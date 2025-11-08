#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int __int128
using namespace std;
constexpr int INF = 0x7fffffff;
int __lcm(int a, int b) { return a / __gcd(a, b) * b; }
void solve() {
    int n, m, y; cin >> n >> m >> y;
    vector<int> a(n);
    for (auto && x : a) cin >> x;
    int ans{};
    for (int i{}; i < (1ll << n); ++ i) {
        vector<int> v;
        for (int j{}; j < n; ++ j) if (i & (1ll << j)) v.emplace_back(j);
        if (v.size() != m) continue;
        int lcm = 1ll;
        for (int x : v) {
            lcm = __lcm(lcm, a[x]);
            if (lcm > y) break;
        }
        if (lcm <= y) ans += y / lcm;
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}