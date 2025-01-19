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
    int ans{};
    priority_queue<int> pq1, pq2;
    for (int i = 0; i < n; ++ i) {
        cin >> a[i];
        pq1.push(a[i]);
        pq2.push(a[i]);
    }
    while (pq1.empty()) {
        int x = pq1.top(); pq1.pop();
        while (!pq2.empty() && pq2.top() < 2 * x) pq2.pop();
        if (pq2.empty()) break;
        pq2.pop();
        ans ++;
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}