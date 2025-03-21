#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for (auto && x : a) cin >> x, mp[x] ++;
    for (auto [x, y] : mp) {
        if (y == 1) { cout << "No\n"; return; }
        if (y > 2) mp[x + 1] += y - 2, y -= 2;
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}