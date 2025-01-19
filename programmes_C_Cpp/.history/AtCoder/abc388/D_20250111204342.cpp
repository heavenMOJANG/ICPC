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
    for (int i = 0; i < n; ++ i) cin >> a[i];
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; ++ i) {
        while (!pq.empty() && pq.top().first < i - pq.top().second) {
            a[pq.top().second] = 0;
            pq.pop();
        }
        pq.push({a[i] + pq.size(), i});
    }
    for (int i = 0; i < n; ++ i) cout << max(0ll, a[i] - (n - 1 - i)) << " \n"[i + 1 == n];
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}