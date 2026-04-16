#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
#define int long long
using namespace std;
using namespace atcoder;

constexpr int MOD = 998244353;

struct S {
    int sum;
};

S op(S a, S b) {
    return {(a.sum + b.sum) % MOD};
}

S e() {
    return {0};
}

using F = int;

S mapping(F f, S x) {
    return {x.sum * f % MOD};
}

F composition(F f, F g) {
    return f * g % MOD;
}

F id() {
    return 1;
}

void solve() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> seg(N);
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        seg[y - 1].push_back(x);
    }

    vector<int> pw2(M + 1, 1);
    for (int i = 1; i <= M; ++i) pw2[i] = pw2[i - 1] * 2 % MOD;

    vector<S> init(N, {0});
    init[0] = {1};  // f[0] = 1
    lazy_segtree<S, op, e, F, mapping, composition, id> segt(init);

    int total = 1;  // 已处理区间的所有子集数

    for (int r = 1; r < N; ++r) {
        auto &v = seg[r];
        sort(v.begin(), v.end());

        int m = (int)v.size();
        total = total * pw2[m] % MOD;

        int L = 0, used = 0;
        for (int i = 0; i < m; ) {
            int x = v[i];
            int j = i;
            while (j < m && v[j] == x) ++j;

            int R = x - 2;
            if (L <= R) {
                segt.apply(L, R + 1, pw2[m - used]);
            }

            used += (j - i);
            L = x - 1;
            i = j;
        }

        if (L <= r - 1) {
            segt.apply(L, r, pw2[m - used]);
        }

        int covered_less = segt.prod(0, r).sum;
        int fr = (total - covered_less + MOD) % MOD;
        segt.set(r, {(segt.get(r).sum + fr) % MOD});
    }

    cout << segt.get(N - 1).sum % MOD << "\n";
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    while (T--) solve();
    return 0;
}
