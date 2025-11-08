#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int dx[] = {-1, 0, 1, 0};
constexpr int dy[] = {0, 1, 0, -1};
void solve() {
    int h, w; cin >> h >> w;
    vector a(h + 2, vector<char> (w + 2, '.'));
    for (int i = 1; i <= h; ++ i)
        for (int j = 1; j <= w; ++ j) cin >> a[i][j];
    int ok = 1;
    for (int i = 1; i <= h; ++ i)
        for (int j = 1; j <= w; ++ j) {
            if (a[i][j] == '.') continue;
            int cnt{};
            for (int k = 0; k < 4; ++ k) {
                int x = i + dx[k], y = j + dy[k];
                if (a[x][y] == '#') cnt ++;
            }
            if (cnt != 2 && cnt != 4) ok = 0;
        }
    cout << (ok ? "Yes\n" : "No\n");
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}