#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    if (n == 1) {cout << "0\n"; return;}
    int minn = LLONG_MAX, s{}, t{};
    for (int l0 = 1; l0 < n; ++ l0) {
        int l1 = n - l0, ft = (1ll << l0) - 1;
        if ((1ll << l0) - 1)
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}