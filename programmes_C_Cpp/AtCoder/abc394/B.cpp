#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++ i) cin >> a[i];
    sort(a.begin(), a.end(), [&](const string& x, const string& y){ return x.size() < y.size(); });
    for (auto s : a) cout << s;
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}