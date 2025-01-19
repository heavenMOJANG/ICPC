#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    int l = m, r = 0, u = n, d = 0;
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < m; ++ j) {
            char ch; cin >> ch;
            if (ch == 'x') {
                l = min(l, j);
                r = max(r, j);
                u = min(u, i);
                d = max(d, i);
            }
        }
    int b = r - l + 1, a = d - u + 1, g = __gcd(a, b);
    a /= g, b /= g;
    for (int i = 0; i < a; ++ i) {
        for (int j = 0; j < b; ++ j) cout << "x";
        cout << "\n";
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}