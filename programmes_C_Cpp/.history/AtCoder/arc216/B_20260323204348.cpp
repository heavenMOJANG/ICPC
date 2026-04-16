#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
void solve() {
    int N, Q; cin >> N >> Q;
    vector<int> A(N + 1), isFixed(N, 0);
    vector<int> preCnt(N + 1, 0), preMin(N + 1, N), sufMin(N + 2, N);
    int M{};
    for (int i = 1; i <= N; ++ i) {
        cin >> A[i];
        preCnt[i] = preCnt[i - 1] + (A[i] != -1);
        preMin[i] = preMin[i - 1];
        if (A[i] != -1) {
            preMin[i] = min(preMin[i], A[i]);
            isFixed[A[i]] = 1;
        } else M ++;
    }
    for (int i = N; i; -- i) {
        sufMin[i] = sufMin[i + 1];
        if (A[i] != -1) {
            sufMin[i] = min(sufMin[i], A[i]);
        }
    }
    vector<vector<pair<int, int>>> b(N + 1);
    vector<int> ans(Q);
    for (int i{}; i < Q; ++ i) {
        int l, r; cin >> l >> r;
        int u = r - l + 1 - (preCnt[r] - preCnt[l - 1]);
        int t = min(preMin[l - 1], sufMin[r + 1]);
        b[t].emplace_back(i, u);
    }
    vector<int> inv(max(2ll, M + 1), 1);
    for (int i = 2; i <= M; ++ i) inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
    int fac = 1;
    for (int i = 2; i <= M; ++ i) (fac *= i) %= MOD;
    vector<int> term(M + 1, fac);
    vector<int> cur(M + 1, 0);
    for (auto [idx, u] : b[0]) ans[idx] = 0;
    int s{};
    for (int v{}; v < N; ++ v) {
        if (!isFixed[v]) {
            int den = M - s;
            int invden = inv[den];
            for (int u = M; u >= s + 1; -- u) term[u] = term[u] * (u - s) % MOD * invden % MOD;
            term[s ++] = 0;
        }
        for (int u = s; u <= M; ++ u) {
            cur[u] += term[u];
            if (cur[u] >= MOD) cur[u] -= MOD;
        }
        for (auto [idx, u] : b[v + 1]) ans[idx] = cur[u];
    }
    for (int i{}; i < Q; ++ i) cout << ans[i] << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}