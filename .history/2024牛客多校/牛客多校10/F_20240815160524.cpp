#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<pair<int, int>> s;
    string ans = "";
    for (int i = 0; i < n * n; ++ i) {
        int x, y; cin >> x >> y;
        map<pair<int, int>, int> mp;
        int cntV{}, cntH{};
        for (auto [tx, ty] : s) {
            if (tx == x) cntV ++;
            else if (ty == y) cntH ++;
            else {
                int dx = x - tx, dy = y - ty;
                int g = __gcd(abs(dx), abs(dy));
                auto pp = {dx / g, dy / g}, pn = {-dx / g, -dy / g};
                mp[{dx / g, dy / g}] ++;
                mp[{-dx / g, -dy / g}] ++;
            }
        }
        int maxn = 0;
        for (auto [p, x] : mp) maxn = max(maxn, x);
        if (cntV < 2 && cntH < 2 && maxn < 2) {
            s.emplace_back(x, y);
            ans += "1";
        }
        else ans += "0";
    }
    cout << ans << "\n";
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}