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
    cout << floor(__lg(129)) << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}