#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m, k; cin >> n >> m >> k;
    int q = (k + n - 1) / n;
    auto check = [&](int x) {
        int res{};
        if (x >= q) return true;
        int s = m / (x + 1);
        res = s * x + m - s * (x + 1);
        return res >= q;
    };
    int l{}, r = 1e9 + 10;
    while (l + 1 < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << r << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}