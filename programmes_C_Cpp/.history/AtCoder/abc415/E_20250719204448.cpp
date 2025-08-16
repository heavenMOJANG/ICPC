#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int h, w; cin >> h >> w;
    vector a(h, vector<int> (w));
    for (int i{}; i < h; ++ i)
        for (int j{}; j < w; ++ j) cin >> a[i][j];
    vector<int> p(h + w - 1);
    for (auto && x : p) cin >> x;
    auto check = [&](int x) {
        vector dp(h, vector<int> (w, -1));
        if (x + a[0][0] >= p[0]) dp[0][0] = x + a[0][0] - p[0];
        else return false;
        for (int i{}; i < h; ++ i)
            for (int j{}; j < w; ++ j) {
                if (!i && !j) continue;
                int d = i + j, cost = p[d], get = a[i][j];
                int U = -1;
                if (i && dp[i - 1][j] != -1)
                    if (dp[i - 1][j] + get >= cost) U = dp[i - 1][j] + get - cost;
                int L = -1;
                if (j && dp[i][j - 1] != -1)
                    if (dp[i][j - 1] + get >= cost) L = dp[i][j - 1] + get - cost;
                dp[i][j] = max(U, L);
            }
        return dp[h - 1][w - 1] != -1;
    };
    int l{}, r = 2e15, ans = r;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}