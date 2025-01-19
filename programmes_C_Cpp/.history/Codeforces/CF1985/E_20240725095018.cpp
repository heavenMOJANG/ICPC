#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int x, y, z, k; cin >> x >> y >> z >> k;
    int maxn = 0;
    for (int i = 1; i <= x; ++ i) {
        if (k % i) continue;
        for (int j = 1; j <= y; ++ j) {
            if ((k / i) % j) continue;
            int res = (x - i + 1) * (y - j + 1) * (z - k / i / j + 1);
            maxn = max(maxn, res);
        }
    }
    cout << maxn << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}