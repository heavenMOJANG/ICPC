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
    map<int, int> mp, cnt;
    for (int i = 0; i < n; ++ i) cin >> a[i], mp[a[i]] ++;
    vector<int> b = a;
    sort(b.begin(), b.end(), greater<int>());
    int rk = 1;
    mp[b[0]] = rk;
    rk += cnt[b[0]];
    for (int i = 1; i < n; ++ i) {
        if (b[i] != b[i - 1]) {
            rk ++;
            mp[b[i]] = rk;
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