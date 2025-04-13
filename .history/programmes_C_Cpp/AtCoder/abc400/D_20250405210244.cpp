#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int dx[] = {0, 1, 0, -1, 0, 2, 0, -2};
constexpr int dy[] = {1, 0, -1, 0, 2, 0, -2, 0};
void solve() {
    int n, m; cin >> n >> m;
    string s[n];
    for (int i{}; i < n; ++ i) cin >> s[i];
    vector dis(n, vector<int> (m, 0)), vis(n, vector<int> (m, 0));
    int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
    dis[sx][sy] = 0;
    deque<pair<int, int>> dq; dq.push_front({sx, sy});
    while (dq.size()) {
        
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}