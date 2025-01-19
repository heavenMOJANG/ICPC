#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int q; cin >> q;
    deque<int> dq;
    int flag{}, cnt{}, t{};
    for (int i = 1; i <= q; ++ i) {
        int op; cin >> op;
        if (op == 1) {

        }
        if (op == 2) {

        }
        if (op == 3) {
            int h; cin >> h;
            int res{};
            while (!dq.empty() && dq.front() + t > h) dq.pop_front(), res ++;
            int siz = dq.size();
            for (int i = 0; i < n; ++ i) {
                
            }
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