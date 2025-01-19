#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int mod = 1e9 + 7;
int fastPow(int a, int x) {
    int res = 1;
    while(x) {
        if (x & 1) res = res * a % mod;
        a = a * a % mod;
        x >>= 1;
    }
    return res;
}
void solve() {
    int n; cin >> n;
    int A = (n * n - 1) % mod;
    int B = fastPow(3 * n - 2, mod - 2);
    cout << A * B % mod << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}