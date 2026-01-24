#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int h, w, n; cin >> h >> w >> n;
    vector a(h + 1, vector<int>(w + 1, 0));
    for (int i = 1; i <= h; ++ i)
        for (int j = 1; j <= w; ++ j) cin >> a[i][j];
    vector<int> cnt(100, 0);
    for (int i{}; i < n; ++ i) {
        int x; cin >> x;
        cnt[x] ++;
    }
    int maxn{};
    for (int i = 1; i <= h; ++ i) {
        int res{};
        for (int j = 1; j <= w; ++ j) if (cnt[a[i][j]]) res ++;
        maxn = max(maxn, res);
    }
    cout << maxn << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}