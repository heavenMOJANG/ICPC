#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int mod = 998244353;
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
    if (n == 1 || n == 2) {cout << "2\n"; return;}
    if (n == 3) {cout << "8\n"; return;}
    if (n == 4) {cout << "16\n"; return;}
    n = n / 2 + 2;
    cout << 
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}