#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    priority_queue<int> pq;
    for (int i = 0; i < n; ++ i) {
        int x; cin >> x;
        pq.push(x);
    }
    int plus{}, minus{};
    int p = 1;
    while (!pq.empty()) {
        int x = pq.top(); pq.pop();
        if (x < p) plus ++;
        if (x > p) minus ++;
        p ++;
    }
    if (plus != minus) cout << "-1\n";
    else cout << plus << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}