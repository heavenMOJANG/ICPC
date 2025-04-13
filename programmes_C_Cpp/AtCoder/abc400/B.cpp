#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int sum{};
    int n, m; cin >> n >> m;
    int mul = 1;
    for (int i{}; i <= m; ++ i) {
        sum += mul;
        if (sum > 1e9) { cout << "inf\n"; return; }
        mul *= n;
    }
    cout << sum << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}