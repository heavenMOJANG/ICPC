#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    unordered_map<int, vector<int>> mp;
    vector<int> a(n), b(n);
    for (int i{}; i < n; ++ i) cin >> a[i];
    for (int i{}; i < n; ++ i) cin >> b[i], mp[a[i] + b[i]].emplace_back(i);
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}