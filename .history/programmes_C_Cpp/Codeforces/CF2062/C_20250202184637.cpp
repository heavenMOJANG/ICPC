#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    int sum{};
    for (auto && x : a) cin >> x, sum += x;
    if (n == 1) { cout << sum << "\n"; return; }
    int m = n - 1;
    while (m >= 0) {
        int res = a[m] - a[0];
        sum = max(abs(res), sum);
        m --;
        for (int i = 0; i < m; ++ i) a[i] = a[i + 1] - a[i];
    }
    cout << sum << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}