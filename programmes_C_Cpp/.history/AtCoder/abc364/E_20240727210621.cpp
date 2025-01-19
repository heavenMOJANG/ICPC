#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n, x, y; cin >> n >> x >> y;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++ i)
        cin >> a[i] >> b[i];
    map<pii, int> dp;
    mp[{0, 0}] = 0;
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}