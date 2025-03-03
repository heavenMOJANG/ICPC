#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, w; cin >> n >> w;
    map<int, priority_queue<pair<int, int>>> mp;
    vector<int> tim(n, INF);
    for (int i = 0; i < n; ++ i) {
        int x, y; cin >> x >> y;
        mp[x].push({y, i + 1});
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}