#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    if (k == n) {
        int p = 2;
        for (; p <= n && a[p] != p / 2; p += 2)
        cout << p / 2 << "\n";
        return;
    }
    int flag{};
    for (int i = 2; i <= n - k + 2; ++ i) if (a[i] != 1) flag = 1;
    cout << (flag ? 1 : 2) << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}