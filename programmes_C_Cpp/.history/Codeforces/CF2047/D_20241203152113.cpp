#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    map<int, int> r;
    for (int i = 0; i < n; ++ i) {
        cin >> a[i].first;
        a[i].second = i;
        r[a[i].first] = max(r[a[i].first], i);
    }
    sort(a.begin(), a.end());
    int pre = r[minn];
    for (int i = 0; i < n; ++ i) {
        if (a[i])
    } 
    cout << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}