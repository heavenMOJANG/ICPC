#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/segtree>
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
void read(i128 & n) {
    i128 x = 0,f = 1;
    char ch =  getchar();
    while (ch <'0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') { x = x * 10 + (ch ^ 48); ch = getchar();}
    n = x * f;
}
void write(i128 n) {
    if (n < 0) {putchar('-'); n *= -1;}
    static __int128 sta[256];
    i128 top{};
    do {
        sta[top ++] = n % 10, n /= 10;
    } while(n);
    while(top) putchar(sta[-- top] + 48);
}
void solve() {
    int n; cin >> n;
    vector<S> a(n);
    for (int i{}; i < n; ++ i) read(a[i].minn);
    atcoder::segtree<S, op, e, F, mapping, composition, id> seg(a.begin(), a.end());
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}