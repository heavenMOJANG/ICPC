#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct S { int x, y; };
S op(S a, S b) { return {a.x + b.x, a.y + b.y}; }
S e() { return {0, 0}; }
using F = int;
S mapping(F f, S a) {
    if (f == 0) a.x = 0;
    if (f == 1) a.x = a.y;
    return a;
}
F composition(F f, F g) { return f == -1 ? g : f; }
F id() { return -1; }
int x, y;
bool fa(S a) { return a.x <= x; }
bool fb(S a) { return a.y <= y; }
void solve() {
    int n, q; cin >> n >> q;
    vector<int> w(n);
    for (auto && x : w) cin >> x;

    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}