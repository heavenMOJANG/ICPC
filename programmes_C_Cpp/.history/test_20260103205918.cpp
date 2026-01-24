#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/segtree>
#define int long long
using namespace std;
using namespace atcoder;
using S = int;
constexpr int MOD = 998244353;
S op(S a, S b) { return (a + b) % MOD; }
S e() { return 0ll; }

void solve() {
    int n; cin >> n;
    vector<int> p(n);
    for (auto && x : p) { cin >> x; x --; } // now p[i] in [0, n-1]

    // 建 size = n，index 有效为 0..n-1
    segtree<S, op, e> slu(n), sld(n), sru(n), srd(n);
    vector<int> dlu(n), dld(n), dru(n), drd(n);

    // 左 -> 右
    for (int i = 0; i < n; ++ i) {
        int x = p[i];
        // 小于 x 的上升结尾和：prod(0, x)
        dlu[i] = (slu.prod(0, x) + 1) % MOD;
        // 大于 x 的下降结尾和：prod(x+1, n)
        dld[i] = sld.prod(x + 1, n) % MOD;

        slu.set(x, (slu.get(x) + dlu[i]) % MOD);
        sld.set(x, (sld.get(x) + dld[i] + 1) % MOD); // +1 把单点作为下降起点计入
    }

    // 右 -> 左
    for (int i = n - 1; i >= 0; -- i) {
        int x = p[i];
        // 后面大于 x 的上升开头和：prod(x+1, n)
        dru[i] = (sru.prod(x + 1, n) + 1) % MOD;
        // 后面小于 x 的下降开头和：prod(0, x)
        drd[i] = srd.prod(0, x) % MOD;

        sru.set(x, (sru.get(x) + dru[i]) % MOD);
        srd.set(x, (srd.get(x) + drd[i] + 1) % MOD);
    }

    int ans = 0;
    for (int i = 0; i < n; ++ i) {
        ans = (ans + dlu[i] * drd[i]) % MOD;
    }
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_ --) solve();
    return 0;
}
