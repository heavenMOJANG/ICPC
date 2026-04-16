#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/segtree>
#define int long long
using namespace std;
using namespace atcoder;
constexpr int INF = 0x7fffffff;
int op(int a, int b) { return a + b; }
int e() { return 0ll; }
int kth(segtree<int, op, e>& seg, int k) {
    int p = seg.max_right(0, [&](int s) { return s < k; });
    return p + 1;
}
void solve() {
    int N, M; cin >> N >> M;
    vector<int> a(N + 1), cnt(M + 1, 0);
    for (int i = 1; i <= N; ++ i) cin >> a[i], cnt[a[i]] ++;
    int Q; cin >> Q;
    vector<int> X(Q + 1);
    for (int i = 1; i <= Q; ++ i) cin >> X[i];
    vector<int> vc(cnt.begin() + 1, cnt.end());
    sort(vc.begin(), vc.end());
    int maxn = vc.back();
    vector<int> pre(M + 1);
    for (int i{}; i < M; ++ i) pre[i + 1] = pre[i] + vc[i];
    auto F = [&](int g) {
        int pos = upper_bound(vc.begin(), vc.end(), g) - vc.begin();
        return (g + 1) * pos - pre[pos];
    };
    int T = M * maxn - N;
    vector<vector<int>> add(maxn + 1);
    for (int i = 1; i <= M; ++ i) add[cnt[i]].emplace_back(i);
    vector<int> ans(Q + 1);
    vector<tuple<int, int, int>> tp;
    for (int i = 1; i <= Q; i++) {
        if (X[i] <= N) { ans[i] = a[X[i]]; continue; }
        int k = X[i] - N;
        if (k > T) { ans[i] = (k - T - 1) % M + 1; continue; }
        int l = -1, r = maxn - 1;
        while (r - l > 1) {
            int mid = (l + r) >> 1;
            if (F(mid) >= k) r = mid;
            else l = mid;
        }
        tp.emplace_back(r, k - F(r - 1), i);
    }
    sort(tp.begin(), tp.end());
    segtree<int, op, e> seg(M);
    int cur{};
    for (auto [g, pos, id] : tp) {
        while (cur <= g) {
            for (int v : add[cur]) seg.set(v - 1, 1);
            cur ++;
        }
        ans[id] = kth(seg, (int)pos);
    }
    for (int i = 1; i <= Q; ++ i) cout << ans[i] << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}