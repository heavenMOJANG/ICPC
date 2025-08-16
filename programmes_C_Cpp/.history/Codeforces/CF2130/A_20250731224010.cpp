#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> cnt(60, 0);
    int sum{};
    for (int i{}; i < n; ++ i) {
        int x; cin >> x;
        cnt[x] ++;
        sum += x;
    }
    int mex{};
    while (cnt[mex]) mex ++;
    int ans = sum + mex - mex * (mex - 1) / 2;
    mex = 0;
    while (cnt[mex] > 1) mex ++;
    ans += mex - mex * (mex - 1) / 2;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}