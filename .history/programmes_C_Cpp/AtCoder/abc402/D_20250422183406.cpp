#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto && x : a) cin >> x;
    vector<int> vis(n + 1, 0);
    function<bool(int)> check = [&](int x) {
        if (x == 0) return true;
        int mex{}, res{};
        for (int i{}; i < x; ++ i) vis[i] = 0;
        for (int i{}; i < n; ++ i) {
            if (a[i] < x && vis[a[i]] == 0) vis[a[i]] = 1, mex ++;
            if (mex == x) {
                res ++;
                mex = 0;
                for (int j{}; j < x; ++ j) vis[j] = 0;
            }
        }
        return res >= k;
    };
    int l{}, r = n + 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) l = mid + 1;
        else r = mid;
    }
    cout << l << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}