#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int l, n; cin >> n >> l;
    vector<int> d(n);
    for (int i = 1; i < n; ++ i) cin >> d[i];
    if (l % 3) { cout << "0\n"; return; }
    int t = l / 3;
    vector<int> p(n);
    p[0] = 0;
    for (int i = 1; i < n; ++ i) p[i] = (p[i - 1] + d[i]) % l;
    map<int, int> ump;
    for (auto x : p) ump[x] ++;
    int ans{};
    for (auto [x, y] : ump) ans += y * ump[(x + t) % l] * ump[(x + 2 * t) % l];
    ans /= 3;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}