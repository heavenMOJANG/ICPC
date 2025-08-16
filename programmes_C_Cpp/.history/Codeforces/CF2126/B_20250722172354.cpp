#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto && x : a) cin >> x;
    int cnt{}, ans{};
    for (int i{}; i < n; ++ i)
        if (!a[i]) {
            cnt ++;
            if (cnt == k) {
                cout << i << " ";
                ans ++;
                cnt = 0;
                i += 1;
                continue;
            }
        } else cnt = 0;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}