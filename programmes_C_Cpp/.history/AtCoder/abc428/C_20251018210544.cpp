#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int q; cin >> q;
    int b = 0, ok = 1;
    vector<char> s;
    while (q --) {
        int op; cin >> op;
        if (op == 1) {
            char c; cin >> c;
            s.push_back(c);
            b += (c == '(' ? 1 : -1);
            if (b < 0) ok = 0;
        } else {
            char lst = s.back(); s.pop_back();
            b += (lst == '(' ? -1 : 1);
            if (lst == ')' && b >= 0 && !s.empty()) ok = 0;
        }
        cout << (b == 0 && ok ? "Yes\n" : "No\n");
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}