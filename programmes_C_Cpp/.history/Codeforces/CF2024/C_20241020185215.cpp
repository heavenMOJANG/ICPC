#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++ i) cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end(), [](const pii & x, const pii & y){
        return x.first == y.first ? x.second < y.second : x.first < y.first;
    });
    for (int i = 0; i < n; ++ i) cout << a[i].first << " " << a[i].second << " \n"[i == n - 1];
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}