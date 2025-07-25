#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int k; cin >> k;
    map<int, int> mp;
    for (int i = 0, x; i < k; ++ i) cin >> x, mp[x] ++;
    k -= 2;
    for (int i = 1; i <= sqrt(k); ++ i) {
        if (k % i) continue;
        int n = i, m = k / i;
        if (n == m && mp[n] >= 2) { cout << n << " " << m << "\n"; return; }
        if (mp[n] && mp[m]) { cout << n << " " << m << "\n"; return; }
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}