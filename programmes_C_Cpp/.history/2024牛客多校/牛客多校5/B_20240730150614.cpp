#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n, m, a, b; cin >> n >> m >> a >> b;
    if (a && b) cout << ((n * m) & 1 ? "No\n" : "Yes\n");
    if (!a && b) cout << ((n == 1) || (m == 1) || (n * m) & 1 ? "No\n" : "Yes\n");
    if (a && !b) cout << ((n == 1 && m % 2 == 0) || (m == 1 && n % 2 == 0) ? "Yes\n" : "No\n");
    if (!a && !b) cout << (n * m == 2 ?  "Yes\n" : "No\n");
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}