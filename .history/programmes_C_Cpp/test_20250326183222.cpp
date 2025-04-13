#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int m, l; cin >> m >> l;
    map<int, int> mp;
    for (int i = 1, x; i <= m * l; ++ i) cin >> x, mp[x] = i;
    int req;
    while (cin >> req && req != -1) {
        if (mp.count(req)) cout << mp[req] << " ";
        else cout << "0 ";
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}