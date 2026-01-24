#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    int tot{};
    for (int i{}; i < n; ++ i) {
        int w, p; cin >> w >> p;
        a[i] = w + p;
        tot += p;
    }
    sort(a.begin(), a.end());
    int ans{}, sum{};
    for (int i{}; i < n; ++ i) {
        if (sum + a[i] <= tot) {
            sum += a[i];
            ans ++;
        } else break;
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}