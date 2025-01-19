#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int q; cin >> q;
    vector<int> a, len;
    int cur{}, pre{}, p{};
    while (q --) {
        int op; cin >> op;
        switch (op) {
            case 1:
                int l; cin >> l;
                len.push_back(l);
                a.emplace_back(cur);
                break;
            case 2:
                pre += len[p];
        default:
            break;
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