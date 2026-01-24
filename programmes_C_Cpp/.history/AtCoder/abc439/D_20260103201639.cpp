#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i{}; i < n; ++ i) cin >> a[i];
    map<int, int> l, r;
    for (auto x : a) r[x] ++;
    int ans{};
    for (int j{}; j < n; ++ j) {
        r[a[j]] --;
        if (a[j] % 5 == 0) {
            int x = a[j] / 5;
            int x7 = 7 * x, x3 = 3 * x;
            ans += l[x7] * l[x3] + r[x7] * r[x3];
        }
        l[a[j]] ++;
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