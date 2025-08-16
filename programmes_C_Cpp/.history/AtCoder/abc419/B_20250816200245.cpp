#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int q; cin >> q;
    priority_queue<int, vector<int>, greater<int>> pq;
    while (q --) {
        int op; cin >> op;
        if (op == 1) {
            int x; cin >> x;
            pq.push(x);
        } else {
            if (pq.empty()) continue;
            cout << pq.top() << "\n";
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