#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int q; cin >> q;
    int vol{}, f{};
    while (q --) {
        int op; cin >> op;
        if (op == 1) vol ++;
        if (op == 2) vol = max(0ll, vol - 1);
        if (op == 3) f ^= 1;
        cout << (f && vol >= 3 ? "Yes\n" : "No\n");
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}