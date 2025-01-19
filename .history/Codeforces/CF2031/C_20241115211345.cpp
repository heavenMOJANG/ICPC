#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    if (n & 1) {
        for (int i = 2; i <= sqrt(n - 1); ++ i) {
            if ((n - 1) % i == 0) 
            {
                int k1 = i, k2 = (n - 1) / i;
            }
        }
    } else
        for (int i = 1; i <= n; i += 2) cout << i << " " << i << " \n"[i == n - 1];
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}