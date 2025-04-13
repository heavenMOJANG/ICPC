#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> a(n);
    for (auto && x : a) cin >> x;
    int ans{};
    for (int i = 0; i < n; ++ i) if (s[i] == 'B') ans = max(ans, a[i]);
    if (!ans || !k) { cout << ans << "\n"; return; }
    auto check = [&](int x) {
        int res{};
        for (int i{}, j{}; i < n; i = j) {
            if (s[j] == 'B' && a[j] > x) {
                for (; j < n && (s[j] == 'B' || (s[j] == 'R' && a[j] <= x)); ++ j);
            } else j ++;
        }
        return res <= k;
    };
    int l = -1, r = 1e9 + 1;
    while (l + 1 != r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << r << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}