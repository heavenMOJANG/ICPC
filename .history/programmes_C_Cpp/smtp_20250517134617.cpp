#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, Y, d; cin >> n >> Y >> d;
    int ans{};
    vector<double> a;
    int c{};
    for (int i{}; i < n; ++ i) {
        int x, y; cin >> x >> y;
        if (y < Y) continue;
        if (x != 0) a.emplace_back(atan2(y, x));
        if (x == 0) c ++;
    }
    sort(a.begin(), a.end());
    n = a.size();
    for (int i{}; i < n; ++ i) {
        int p = lower_bound(a.begin() + i, a.end(), atan2()) - a.begin();
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