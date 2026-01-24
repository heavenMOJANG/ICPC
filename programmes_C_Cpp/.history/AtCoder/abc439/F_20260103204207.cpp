#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/segtree>
#define int long long
using namespace std;
using namespace atcoder;
using S = int;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
S op(S a, S b) { return (a + b) % MOD; }

void solve() {
    int n; cin >> n;
    vector<int> p(n);
    for (auto && x : p) cin >> x, x --;

    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}