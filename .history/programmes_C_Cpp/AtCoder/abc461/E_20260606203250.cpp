#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/segtree>
#define int long long
using namespace std;
using namespace atcoder;
using S = int;
constexpr int INF = 0x7fffffff;
S op(int a, int b) { return a + b; }
S e() { return 0ll; }
void solve() {
    int N, Q; cin >> N >> Q;
    vector<int> R(N + 1, 0), C = R;
    segtree<S, op, e> sr(Q + 1), sc(Q + 1);
    sr.set(0, N); sc.set(0, N);

    int cur{};
    for (int i{1}; i <= Q; ++ i) {
        int opt, id; cin >> opt >> id;
        if (opt == 1) {
            int old = R[id];
            cur += N - sc.prod(0, old);
            sr.set(old, sr.get(old) - 1);
            R[id] = i;
            sr.set(i, sr.get(i) + 1);
        } else {
            int old = C[id];
            cur -= N - sr.prod(0, old + 1);
            sc.set(old, sc.get(old) - 1);
            C[id] = i;
            sc.set(i, sc.get(i) + 1);
        }
        cout << cur << "\n";
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}