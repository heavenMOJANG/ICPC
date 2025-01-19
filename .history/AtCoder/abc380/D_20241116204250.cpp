#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
char rev(char c) {
    if ('a' <= c && c <= 'z') return c - 32;
    else return c + 32;
}
void solve() {
    string s; cin >> s;
    int n = s.size();
    int q; cin >> q;
    for (int i = 1; i <= q; ++ i) {
        int x; cin >> x;
        if (x <= n) cout << s[x - 1] << " \n"[i == q]
        else {
            int p = (x - 1) % (2 * n) + 1;
            if (p <= n) cout << s[p] << " \n"[i == q];
            else ans.emplace_back(s[p - n]);
        }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}