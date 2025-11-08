#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> h(n);
    for (auto && x : h) cin >> x; sort(h.begin(), h.end());
    priority_queue<int, vector<int>, greater<int>> b;
    for (int i{}; i < m; ++ i) {
        int x; cin >> x;
        b.push(x);
    }
    int cnt{};
    for (int i{}; i < n; ++ i) {
        while (!b.empty() && b.top() < h[i]) b.pop();
        if (b.empty()) break;
        b.pop();
        cnt ++;
    }
    cout << (cnt >= k ? "Yes\n" : "No\n");
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}