#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/segtree>
#define int long long
using namespace std;
using namespace atcoder;
constexpr int INF = 0x7fffffff;
using S = int;
S op(S a, S b) { return max(a, b); }
S e() { return 0ll; }
void solve() {
    int N, M; cin >> N >> M;
    vector<vector<int>> LR(N + 1);
    vector<vector<int>> RL(N + 1);
    for (int i{}; i < N; ++ i) {
        int L, R; cin >> L >> R;
        LR[R].emplace_back(L);
        RL[L].emplace_back(R);
    }
    int Q; cin >> Q;
    vector<vector<pair<int, int>>> query(N + 1);
    for (int i{}; i < Q; ++ i) {
        int S, T; cin >> S >> T;
        query[T].emplace_back(S, i);
    }
    vector<string> ans(Q);
    vector<int> best(N + 1, -1);
    segtree<int, op, e> seg(N + 2);
    for (int T = 1; T <= N; ++ T) {
        for (int L : LR[T]) {
            seg.set(L, 1);
            best[L] = max(best[L], T);
        }
        for (auto [S, idx] : query[T]) {
            if (best[S] == -1) { ans[idx] = "No"; continue; }
            int R = best[S] + 1;
            R = min(R, N);
            int maxn = seg.prod(S, R + 1);
            ans[idx] = (maxn ? "Yes" : "No");
        }
    }
    for (string s : ans) cout << s << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}
