#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> p;
    for (int i{}; i < m; ++ i) {
        int a, b; cin >> a >> b;
        if (a <= n) p.emplace_back(a - b, a);
    }
    sort(p.begin(), p.end());
    int e = n, ans{};
    for (auto [a, b] : p) {
        if (e < b) continue;
        int k = (e - b) / a + 1;
        ans += k;
        e -= k * a;
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