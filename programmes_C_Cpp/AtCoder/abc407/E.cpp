#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(2 * n);
    for (int i{}; i < 2 * n; ++ i) cin >> a[i];
    int sum = accumulate(a.begin(), a.end(), 0ll);
    priority_queue<int> pq;
    int res{};
    for (int i{}; i < 2 * n; ++ i) {
        pq.push(a[i]);
        res += a[i];
        if (pq.size() > (i + 1) / 2) { res -= pq.top(); pq.pop(); }
    }
    cout << sum - res << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}