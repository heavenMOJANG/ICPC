#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int q; cin >> q;
    vector<int> pre;
    pre.emplace_back(0);
    int p{}, n = 1;
    while (q --) {
        int op; cin >> op;
        switch (op) {
            case 1:
                int l; cin >> l;
                pre.emplace_back(pre.back() + l);
                n ++;
                break;
            case 2:
                p ++;
                break;
            case 3:
                int k; cin >> k;
                cout << pre[p + k] - pre[p] << "\n";
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