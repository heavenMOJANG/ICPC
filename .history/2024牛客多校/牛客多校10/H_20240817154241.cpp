#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
int fastPow(int a, int x) {
    int res = 1;
    while (x) {
        if (x & 1) res = res * a % MOD;
        a = a * a % MOD;
        x >>= 1;
    }
    return res;
}
int getInv(int x) {
    return fastPow(x, MOD - 2);
}
void solve() {
    int a, b; cin >> a >> b;
    int c = getInv(a + b);
    cout << a * c % MOD << " " << b * c % MOD << "\n";
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}