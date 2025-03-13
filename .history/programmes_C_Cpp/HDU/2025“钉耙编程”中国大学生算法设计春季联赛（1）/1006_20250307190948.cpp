#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; ++ i) {
        vector<int> a(3);
        cin >> a[0] >> a[1] >> a[2];
        do {
            int k = (a[2] - a[1]) / a[0], r = (a[2] - a[1]) % a[0];
            if (k >= 0 && r == 0) mp[k] ++;
            cout << k << " " << r << "\n";
        } while (next_permutation(a.begin(), a.end()));
    }
    for (auto [x, y]:mp) if (y == n) { cout << x << "\n"; return; }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}