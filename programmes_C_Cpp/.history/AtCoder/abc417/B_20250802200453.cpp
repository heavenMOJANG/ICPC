#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    priority_queue<int> pq;
    for (auto && x : a) cin >> x;
    for (int i{}; i < m; ++ i) {
        int x; cin >> x;
        pq.push(x);
    }
    for (int i{}; i < n; ++ i) {
        if (!pq.empty() && pq.top() == a[i]) { pq.pop(); continue; }
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}