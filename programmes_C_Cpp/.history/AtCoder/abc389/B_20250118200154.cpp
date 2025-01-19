#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    unsigned long long x; cin >> x;
    unsigned res = 1;
    for (unsigned long long i = 1; res <= x; ++ i) {
        res *= i;
        if (res == x) { cout << i << "\n"; return; }
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}