#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 0x7fffffff;
bool check(const string& s, const string& t) {
    if (s.size() > t.size()) return 0;
    return s == t.substr(0, s.size());
}
void solve() {
    int q; cin >> q;
    multiset<string> x, y;
    while (q --) {
        string t, s; cin >> t >> s;
        if (t == "1") {
            auto it = x.upper_bound(s);
            if (it != x.begin() && check(*prev(it), s)) {}
            else {
                while (it != x.end() && check(s, *it)) it = x.erase(it);
                it = y.lower_bound(s);
                while (it != y.end() && check(s, *it)) it = y.erase(it);
                x.insert(s);
            }
        } else {
            auto it = x.upper_bound(s);
            if (it != x.begin() && check(*prev(it), s)) {}
            else y.insert(s);
        }
        cout << y.size() << "\n";
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}