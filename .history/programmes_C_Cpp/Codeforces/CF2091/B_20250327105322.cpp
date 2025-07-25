#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, x; cin >> n >> x;
    priority_queue<int> pq;
    int ans{};
    for (int i = 0; i < n; ++ i) {
        int a; cin >> a;
        if (a >= x) ans ++;
        else pq.push(a);
    }
    int cnt{}, tp{};
    while (!pq.empty()) {
        tp = pq.top(); pq.pop();
        if (tp * 2 >= x) ans ++;
        else cnt ++;
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}