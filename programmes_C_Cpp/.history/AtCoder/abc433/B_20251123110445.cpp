#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto && x : a) cin >> x;
    priority_queue<int> pq;
    for (int i{}; i < n; ++ i) {
        while (!pq.empty() && a[pq.top()] <= a[i]) pq.pop();
        cout << (pq.empty() ? -1 : pq.top() + 1) << " \n"[i == n - 1];
        pq.push(i);
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}