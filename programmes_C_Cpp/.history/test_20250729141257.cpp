#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto && x : a) cin >> x;
    int maxn = *max_element(a.begin(), a.end());
    int bit{};
    while ((1ll << bit) <= maxn) bit ++;
    int ans{};
    vector<int> pre(n, 0);
    for (int k{}; k < bit; ++ k) {
        int n00{}, n01{}, n10{}, n11{};
        for (int i{}; i < n; ++ i) {
            int x = (a[i] >> k) & 1;
            pre[i] ^= x;
            int y = pre[i];
            if (!x) {
                if (!y) n00 ++;
                else n01 ++;
            } else {
                if (!y) n10 ++;
                else n11 ++;
            }
        }
        int cnt = n00 * n11 + n01 * n10;
        ans += cnt << k;
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