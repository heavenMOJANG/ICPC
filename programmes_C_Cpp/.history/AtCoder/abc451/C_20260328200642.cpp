#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int Q; cin >> Q;
    multiset<int> ms;
    while (Q --) {
        int op, h; cin >> op >> h;
        if (op == 1) ms.insert(h);
        else {
            auto it = ms.upper_bound(h);
            ms.erase(ms.begin(), it);
        }
        cout << ms.size() << "\n";
    }
    
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}