#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq[2];
    for (int i{}, x; i < n; ++ i) cin >> x, pq[i % 2].push(x);
    for (int i{}; i < n / 2; ++ i) {
        cout << pq[0].top() << " "; pq[0].pop();
        cout << pq[1].top() << " "; pq[1].pop();
    }
    if(!pq[0].empty()) cout << pq[0].top() << "\n";
    else cout << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}