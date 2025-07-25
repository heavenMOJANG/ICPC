#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m, a, b; cin >> n >> m >> a >> b;
    function<int<int, int>> calc = [&](int x, int y) {
        int res = 1;
        while (x != 1) x = x + 1 >> 1, res ++;
        while (y != 1) y = y + 1 >> 1, res ++;
        return res;
    };
    int ans = LLONG_MAX;
    ans = min({calc(n - a, m), calc(a + 1, m), calc(n, m - b), calc(n, b + 1)});
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}