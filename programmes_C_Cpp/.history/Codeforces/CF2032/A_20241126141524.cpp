#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> s(2, 0);
    for (int i = 0, x; i < (n << 1); ++ i) s[x] ++;
    if (s[1] <= n) {
        cout << n - s[1] << " " << n - s[1] / 2 << "\n";
    } else {

    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}