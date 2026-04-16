#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/segtree>
#define int long long
using namespace std;
using namespace atcoder;
using S = int;
constexpr int INF = 0x7fffffff;
S op (S a, S b) { return a + b; }
S e () { return 0ll; }
void solve() {
    int N, K; cin >> N >> K;
    vector<int> P(N + 1);
    for (int i = 1; i <= N; ++ i) cin >> P[i];
    auto getF = [&](int tar) -> vector<int> {
        vector<int> f(N + 1);
        segtree<int, [](int a, int b) { return a + b; }, [](){ return 0ll; }> seg(N + 1);
        int R = 1, inv{};
        for (int L = 1; L <= N; ++ L) {
            if (R < L) R = L, inv = 0;
            while (R <= N && inv < tar) {
                inv += seg.prod(P[R] + 1, N + 1);
                seg.set(P[R], seg.get(P[R]) + 1);
                R ++;
            }
            f[L] = (inv >= tar) ? R - 1 : N + 1;
            f[L] = max(L, f[L]);
            if (R > L) {
                inv -= seg.prod(1, P[L]);
                seg.set(P[L], seg.get(P[L]) - 1);
            }
        }
        return f;
    };
    vector<int> f1 = getF(K), f2 = getF(K + 1);
    int ans{};
    for (int L = 1; L <= N; ++ L) ans += max(0ll, f2[L] - f1[L]);
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}
