#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> mark(n + 1, 0);
    priority_queue<int> pq;
    for (int i = 0; i < n; ++ i) {
        int x; cin >> x;
        if (x <= n && !mark[x]) mark[x] = 1;
        else pq.push(x);
    }
    int plus{}, minus{};
    int p = 1;
    while (!pq.empty()) {
        while (p <= n && mark[p]) p ++;
        int x = pq.top(); pq.pop();
        cout << x << "\n";
        if (x < p) plus ++;
        else minus ++;
        mark[p ++] = 1;
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