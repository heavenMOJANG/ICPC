#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int q; cin >> q;
    stack<int> s;
    for (int i = 0; i < 100; ++ i) s.push(0);
    while (q --) {
        int opt; cin >> opt;
        if (opt == 1) {
            int x; cin >> x;
            s.push(x);
        } else {
            cout << s.top() << "\n";
            s.pop();
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