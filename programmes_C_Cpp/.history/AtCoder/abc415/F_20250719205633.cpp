#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct segtree {
    int val, len, llen, rlen;
    char lc, rc;
    segtree() : val{}, len{}, llen{}, rlen{}, lc{}, rc{} {}
    segtree(char ch) : val(1), len(1), llen(1), rlen(1), lc(ch), rc(ch) {}
};
void pushUp(int p, int pl, int pr) {
    
}
void solve() {
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}