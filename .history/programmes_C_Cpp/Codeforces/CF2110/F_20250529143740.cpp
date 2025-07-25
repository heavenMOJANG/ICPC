#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> b(n + 1), a(n + 1);
    int maxn = b[1]; a[1] = 0;
    for (int i = 2; i <= n; ++ i) {
        if (b[i] <= maxn) a[i] = b[i] % maxn + maxn % b[i];
        if (maxn < b[i] && b[i] < 2 * maxn) a[i] = b[i];
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}