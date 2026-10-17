#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int Q, V; cin >> Q >> V;
    priority_queue<int> pq;
    while (Q --) {
        int op, t; cin >> op >> t;
        if (op == 1) {
            int w; cin >> w;
            pq.push(w - t);
        } else {
            if (pq.empty()) { cout << "-1\n"; continue; }
            cout << min(V, t + pq.top()) << "\n";
            pq.pop();
        }
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}