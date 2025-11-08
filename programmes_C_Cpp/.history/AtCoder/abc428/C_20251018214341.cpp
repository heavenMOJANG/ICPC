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
            s.emplace(c);
            if (c == ')') {
                if (b) b --;
                else cnt ++;
            } else b ++;
        } else {
            char lst = s.top(); s.pop();
            if (lst == ')') {
                if (cnt) cnt --;
                else b ++;
            } else b --;
        }
        cout << (b == 0 && cnt == 0 ? "Yes\n" : "No\n");
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}