#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int x, y; cin >> x >> y;
    set<pair<int, int>> s;
    for (int i = 1; i <= 6; ++ i)
        for (int j = 1; j <= 6; ++ j) {
            if (i + j >= x) s.insert({i, j});
            if (abs(i - j) >= y) s.insert({i, j});
        }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}