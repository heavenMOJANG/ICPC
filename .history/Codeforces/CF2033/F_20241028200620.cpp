#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 1e9 + 7;
void solve() {
    int n, k; cin >> n >> k;
    int p = 3;
    int a = 1, b = 1, c{};
    while (1) {
        c = (a + b) % k;
        if (!c) break;
        p ++;
        a = b, b = c;
    }
    if (k == 1) cout << "1\n";
    else cout << (n % MOD) * (p % MOD);
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}