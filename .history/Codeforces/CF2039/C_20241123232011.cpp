#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int x, m; cin >> x >> m;
    vector<int> fac;
    set<int> fac;
    for (int i = 1; i <= sqrt(x); ++ i) {
        if (x % i) continue;
        if (i * i == x) fac.emplace_back(i);
        else {
            fac.emplace_back(i);
            fac.emplace_back()
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