#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
#define i128 __int128
using namespace std;
constexpr int INF = 0x7fffffff;
struct S { i128 minn; };
using F = i128;
S op (S a, S b) { return {min(a.minn, b.minn)}; }
S e() { return {(i128)1 << 120}; }
S mapping (F f, S x) { return {x.minn + f}; }
F composition (F f, F g) { return f + g; }
F id() { return 0; }

void solve() {
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}