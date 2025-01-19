#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int Q; cin >> Q;
    queue<int> q;
    vector<int> h(Q + 1);
    for (int i = 0; i < Q; ++ i) {
        int op; cin >> op;
        if (op == 1) {
            h[i + 1] = h[i];
            q.push(i);
        }
        if (op == 2) {
            int T; cin >> T;
            h[i + 1] = h[i] + T;
        }
        if (op == 3) {
            h[i + 1] = h[i];
            int H; cin >> H;
            int res{};
            while (!q.empty()) {
                if (H[i + 1] - H[q.front()] >= h) res ++, q.pop();
                else break;
            }
            cout << res << "\n";
        }
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}