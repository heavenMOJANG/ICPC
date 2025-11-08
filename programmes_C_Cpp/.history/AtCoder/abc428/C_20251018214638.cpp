#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int q; cin >> q;
    stack<pair<int, int>> s;
    while (q --) {
        int op; cin >> op;
        if (op == 1) {
            char c; cin >> c;
            auto [b, m] = s.top();
            int nb, nm;
            if (c == '(') {
                nb = b + 1;
                nm = min(m, nb);
            } else {
                nb = b - 1;
                nm = min(m, nb);
            }
            s.emplace(nb, nm);
        } else s.pop();
        auto [b, m] = s.top();
        cout << (m >= 0 && b == 0 ? "Yes\n" : "No\n");
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}