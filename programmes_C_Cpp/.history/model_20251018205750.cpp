#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int q; cin >> q;
    int s{};
    vector<char> v;
    while (q --) {
        int op; cin >> op;
        if (op == 1) {
            char c; cin >> c;
            v.emplace_back(c);
            s += (c == '(' ? -1 : 1);
        } else {
            s += (v.back() == '(' ? 1 : -1);
            v.pop_back();
        }
        cout << (!s ? "Yes\n" : "No\n");
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}