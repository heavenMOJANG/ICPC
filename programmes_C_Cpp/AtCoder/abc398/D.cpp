#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, r, c; cin >> n >> r >> c;
    string s; cin >> s;
    string ans{};
    int x{}, y{};
    map<pair<int, int>, int> mp;
    mp[{0, 0}] = 1;
    for (int i = 0; i < n; ++ i) {
        switch (s[i]) {
            case 'N': x --; break;
            case 'S': x ++; break;
            case 'W': y --; break;
            case 'E': y ++; break;
        }
        int dx = x - r, dy = y - c;
        if (mp.count({dx, dy}) != 0) ans += "1";
        else ans += "0";
        mp[{x, y}] = 1;
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