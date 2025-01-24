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
    sort(a.begin(), a.end());
    for (auto [x, y] : mp) {
        if (y < 2) continue;
        switch(x) {
            case 2:
                for (int i = 0; i < n; ++ i) {
                    if (a[i] == x) continue;
                    int p = lower_bound(a.begin() + i, a.end(), x * 2 + a[i]) - a.begin();
                    if ()
                }
        }
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}