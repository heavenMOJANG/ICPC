#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    vector<int> p0, p1;
    for (int i = 2; i < n; ++ i) {
        if (a[i - 1] < a[i] && a[i] > a[i + 1]) p0.emplace_back(i);
        if (a[i - 1] > a[i] && a[i] < a[i + 1]) p1.emplace_back(i);
    }
    int ans{};
    for (int i = 1; i < n; ++ i) {
        if (a[i] >= a[i + 1]) continue;
        int i0 = upper_bound(p0.begin(), p0.end(), i) - p0.begin();
        int i1 = upper_bound(p1.begin(), p1.end(), i) - p1.begin();
        if (i0 == p0.size() || i1 == p1.size()) break;
        if (p0[i0] > p1[i1]) {
            if (i1 + 1 < p1.size() && p1[i1 + 1] < p0[i0]) continue;
            if (p0[i0] + 1 - i + 1 < 4) continue;
        }
        if (p1[i1] > p0[i0]) {
            if (i0 + 1 < p0.size() && p0[i0 + 1] < p1[i1]) continue;
            if (p1[i1] + 1 - i + 1 < 4) continue;
        }
        int nexp = LLONG_MAX;
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}