#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, Y, d; cin >> n >> Y >> d;
    vector<double> p;
    for (int i{}; i < n; ++ i) {
        int x, y; cin >> x >> y;
        if (y < Y) continue;
        double X = x * 1.0 * Y / y;
        p.emplace_back(X);
    }
    sort(p.begin(), p.end());
    n = p.size();
    int ans{};
    for (int l{}, r{}; l < n; ++ l) {
        while (r + 1 < n) {
            if (p[r + 1] - p[l] <= d) r ++;
            else break;
        }
        ans = max(ans, r - l + 1);
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