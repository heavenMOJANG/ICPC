#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    map<int ,int> mp;
    for (int i = 1; i <= n; ++ i) mp[(i - 1) * (n - i + 1) + (n - i)] ++;
    for (int i = 1; i < n; ++ i) mp[i * (n - i)] += (a[i + 1] - a[i] - 1);
    while (q --) {
        int k; cin >> k;
        cout << mp[k] << "\n";
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}