#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int a, c, p; cin >> a >> c >> p;
    function<int(int, int)> qpow = [&](int a, int x) {
        int res = 1;
        while (x) {
            if (x & 1) res = res * a % p;
            a = a * a % p;
            x >>= 1;
        }
        return res;
    };
    int l = 1, r = 1e18;
    while (l < r) {
        int b = l + r >> 1;
        int vl = qpow(a, b % (p - 1)), vr = qpow(b % p, c);
        cout << vl << " " << vr << "\n";
        if (vl == vr) { cout << m << "\n"; break; }
        else {
            if (vl > vr) r = b;
            else l = b + 1;
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