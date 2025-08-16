#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, x; cin >> n >> x;
    string s; cin >> s;
    int wl{}, wr{}, el{}, er{};
    for (int i{}; i < x - 1; ++ i) if (s[i] == '#') wl ++;
    el = x - 1 - wl;
    for (int i = x; i < n; ++ i) if(s[i] == '#') wr ++;
    er = n - x - wr;
    if (!wl || !wr) { cout << "1\n"; return; }
    cout << min(max(wl + el, wr) + 1, max(wr + er, wl) + 1) << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}