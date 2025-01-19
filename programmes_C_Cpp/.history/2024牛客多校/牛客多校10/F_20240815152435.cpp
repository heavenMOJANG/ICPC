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
    for (int i = 0; i < n; ++ i) {
        int x, y; cin >> x >> y;
        map<pair<int, int>, int> mp;
        int cnt = 0;
        for (auto [xx, yy] : s) {
            if (xx == x) cnt ++;
            else {
                int dx = xx - x, dy = yy - y;
                int g = __gcd(dx, dy);
                mp[{dx / g, dy / g}] ++;
        }
        auto [aa, bb] = max_element(mp.begin(), mp.end(), [](const auto & a, const auto & b) {return a.second < b.second;});
        if ()
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}