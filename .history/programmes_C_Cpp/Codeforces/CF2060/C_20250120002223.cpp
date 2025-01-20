#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    vector<int> x(n);
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, less<int>> pq2;
    for (int i = 0; i < n; ++ i) cin >> x[i], pq1.push(x[i]), pq2.push(x[i]);
    int ans{}, sum{};
    while (!pq1.empty()) {
        
    }
    if (sum & 1) cout << "0\n";
    else cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}