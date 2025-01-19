#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int x, y; cin >> x >> y;
    int cnt = 0;
    while ( (x & 1) ^ (y & 1) == 0) {
        x >>= 1;
        y >>= 1;
        cnt ++;
    }
    cout << (1ll << cnt) << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}