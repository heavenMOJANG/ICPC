#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, l, r; cin >> n >> l >> r;
    vector<int> a(n);
    priority_queue<int, vector<int>, greater<int>> pq1, pq2;
    for (int i = 0; i < n; ++ i) {
        cin >> a[i];
        if (i < r) pq1.push(a[i]);
        if (i >= l - 1) pq2.push(a[i]);
    }
    int sum1{}, sum2{};
    for (int i = 0; i < r - l + 1; ++ i) {
        sum1 += pq1.top(); pq1.pop();
        sum2 += pq2.top(); pq2.pop();
    }
    cout << min(sum1, sum2) << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}