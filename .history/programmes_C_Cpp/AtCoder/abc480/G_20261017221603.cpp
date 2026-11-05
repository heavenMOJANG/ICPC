#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
#define int long long
using namespace std;
using namespace atcoder;
using S = int;
using F = int;
constexpr int INF = 1ll << 60;
S op(S a, S b) { return min(a, b); }
S e() { return INF; }
F mapping(F f, S x) { return f + x; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }
void solve() {
    int N; cin >> N;
    vector<int> A(N);
    for (auto && x : A) cin >> x;
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(N);
    vector<int> dp(N + 1, INF), sMax, sMin;
    dp[0] = 0;
    for (int i : views::iota(0, N)) {
        if (i >= 1) seg.set(i - 1, dp[i - 1]);
        while (!sMax.empty() && A[sMax.back()] <= A[i]) {
            int j{sMax.back()}; sMax.pop_back();
            int l{sMax.empty() ? 0 : sMax.back() + 1};
            seg.apply(l, j + 1, A[i] - A[j]);
        }
        sMax.emplace_back(i);
        while (!sMin.empty() && A[sMin.back()] >= A[i]) {
            int j{sMin.back()}; sMin.pop_back();
            int l{sMin.empty() ? 0 : sMin.back() + 1};
            seg.apply(l, j + 1, A[j] - A[i]);
        }
        sMin.emplace_back(i);
        dp[i + 1] = seg.all_prod();
    }
    cout << dp[N] << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}