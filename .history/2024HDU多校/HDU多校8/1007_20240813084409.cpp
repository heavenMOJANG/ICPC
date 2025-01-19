#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int a, b, c; cin >> a >> b >> c;
    if (a + b < c) {cout << "0\n"; return;}
    if (a + b == c) {cout << "-1\n"; return;}
    int ans = 0;
    auto check = [&](int a, int b, int c, int k) {
        int res = 0, f = 1;
        while(a || b) {
            res += f * ((a + b) % k);
            a /= k;
            b /= k;
            f *= k;
        }
        return res == c;
    };
    for (int i = 2; i <= sqrt(a + b - c); ++ i) {
        ans += check(a, b, c, i);
        if (i * i != (a + b - c)) ans += check(a, b, c, (a + b - c) / i);
    }
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}