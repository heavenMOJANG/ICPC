#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/segtree>
#define int long long
#define pii pair<int, int>
using namespace std;
using namespace atcoder;
constexpr int INF = 0x7fffffff;
using S = int;
S op(S a, S b) { return a + b; }
S e() { return 0ll; }
void solve() {
    int N, M; cin >> N >> M;
    vector<vector<int>> LR(N + 1);
    vector<vector<int>> RL(N + 1);
    for (int i{}; i < M; ++ i) {
        int L, R; cin >> L >> R;
        LR[L].emplace_back(R);
        RL[R].emplace_back(L);
    }
    for (int i{1}; i <= N; ++ i) {
        sort(LR[i].begin(), LR[i].end());
        sort(RL[i].begin(), RL[i].end());
    }
    int Q; cin >> Q;
    vector<vector<pair<int, int>>> query(N + 1);
    for (int i{}; i < Q; ++ i) {
        int S, T; cin >> S >> T;
        query[S].emplace_back(T, i);
    }
    vector<int> ans(Q, 0), cnt(Q, 0);
    segtree<int, op, e> seg(N + 2);
    for (int S = N; S >= 1; -- S) {
        for (int R : LR[S]) seg.set(R, seg.get(R) + 1);
        for (auto [T, idx] : query[S]) cnt[idx] = seg.prod(1, T + 1);
    }
    for (int S = 1; S <= N; ++ S)
        for (auto [T, idx] : query[S]) {
            bool ok = binary_search(LR[S].begin(), LR[S].end(), T);
            if (ok) {
                if (cnt[idx] >= 2) ans[idx] = 1;
            } else {
                auto itR = upper_bound(LR[S].begin(), LR[S].end(), T);
                int maxr = -1;
                if (itR != LR[S].begin()) maxr = *prev(itR);
                auto itL = lower_bound(RL[T].begin(), RL[T].end(), S);
                int minl = INF;
                if (itL != RL[T].end()) minl = *itL;
                if (maxr != -1 && minl != INF && minl <= maxr + 1)
                    ans[idx] = 1;
            }
        }
    for (int s : ans) cout << (s ? "Yes\n" : "No\n");
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}