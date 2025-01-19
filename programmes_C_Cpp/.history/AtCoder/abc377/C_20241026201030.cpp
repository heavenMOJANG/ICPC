#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
const int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
void solve() {
    int n, m; cin >> n >> m;
    map<pair<int, int>, int> mp;
    while (m --) {
        int x, y; cin >> x >> y;
        for (int i = 0; i < 8; ++ i) {
            int tx = x + dx[i], ty = y + dy[i];
            if (tx < 1 || tx > n || ty < 1 || ty > n) continue;
            mp[{tx, ty}] = 1;
        }
    }
    cout << n * n - mp.size() << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}