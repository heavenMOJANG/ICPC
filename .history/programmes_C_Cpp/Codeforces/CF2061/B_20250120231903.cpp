#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; ++ i) cin >> a[i], mp[a[i]] ++;
    set<int> s2, s3;
    for (auto [x, y] : mp) {
        if (y == 2) s2.insert(x);
        if (y == 3) {
            
        }
        if (y >= 4) {
            for (int i = 0; i < 4; ++ i) cout << x << " \n"[i == 3];
            return;
        }
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n - 1; ++ i) {
        int d = a[i + 1] - a[i];
        auto p = lower_bound(s2.begin(), s2.end(), d / 2);
        while (p != s2.end() && ( *p == a[i] || *p != a[i + 1] || *p * 2 + a[i] <= a[i + 1])) p ++;
        if (p != s2.end()) {
            cout << a[i] << " " << a[i + 1] << " " << *p << " " << *p << "\n";
            return;
        }
    }
    cout << "-1\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}