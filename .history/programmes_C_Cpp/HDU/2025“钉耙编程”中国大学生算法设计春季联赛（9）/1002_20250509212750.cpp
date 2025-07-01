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
    for (int i{}; i < n; ++ i) cin >> a[i];
    vector<int> b(n - 1);
    for (int i{}; i < n - 1; ++ i) b[i] = a[i + 1] - a[i];
    int cnt{};
    for (int i{}; i < n - 1; ++ i) {
        int k{};
        while (i - k >= 0 && i + k < n - 1 && b[i - k] == b[i + k]) cnt ++, k ++;
    }
    for (int i{}; i < n - 2; ++ i)
        if (b[i] == b[i + 1]) {
            cnt ++;
            int k = 1;
            while (i - k >= 0 && i + 1 + k < n - 1 && b[i - k] == b[i + 1 + k]) cnt ++, k ++;
        }
    cout << n + cnt << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}