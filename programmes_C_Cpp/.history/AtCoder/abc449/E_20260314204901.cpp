#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
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
    vector<int> b;
    vector<int> vc(b.begin() + 1, b.end());
    sort(vc.begin(), vc.end());
    int maxn = vc.end();
    
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}