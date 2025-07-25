#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
char rev(char c) {
    return islower(c) ? toupper(c) : tolower(c);
}
int lowbit(int x) { return x & (-x); }
void solve() {
    string s; cin >> s;
    int n = s.size();
    int q; cin >> q;
    for (int i = 1; i <= q; ++ i) {
        int x; cin >> x;
        if (x <= n) cout << s[x - 1] << " \n"[i == q];
        else {
            int k = (x - 1) / n, r = (x - 1) % n;
            if (!r) k ++, r = n;
            if (__builtin_popcount(k) & 1) cout << rev(s[r]) << " \n"[i == q];
            else cout << s[r] << " \n"[i == q];
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