#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/segtree>
#define int long long
using namespace std;
using namespace atcoder;
constexpr int INF = 4e18;
struct S { int sum, max; };
S op(S a, S b) { return {a.sum + b.sum, max(b.max, a.max + b.sum)}; }
S e() { return {0, -INF}; }
void solve() {
    int N, Q; cin >> N >> Q;
    vector<int> A(N + 1), B(N + 1);
    for (int i : views::iota(1, N + 1)) cin >> A[i];
    for (int i : views::iota(1, N + 1)) cin >> B[i];
    struct Query { int op, i, x; };
    vector<Query> query(Q);
    vector<int> v;
    for (int i : views::iota(1, N + 1)) v.emplace_back(B[i]);
    for (auto && [op, i, x] : query) {
        cin >> op >> i >> x;
        if (op == 2) v.emplace_back(x);
    }
    ranges::sort(v);
    auto [fi, se] = ranges::unique(v);
    v.erase(fi, se);
    auto get = [&](int x) { return ranges::lower_bound(v, x) - v.begin(); };
    int M{(int)v.size()};
    vector<int> s(M, 0);
    for (int i : views::iota(1, N + 1)) s[get(B[i])] += A[i];
    vector<S> to_seg(M);
    for (auto [i, x] : views::enumerate(s))
        if (x) to_seg[i] = {x, x + v[i]};
        else to_seg[i] = e();
    segtree<S, op, e> seg(to_seg);
    auto upd = [&](int pos) {
        if (s[pos]) seg.set(pos, {s[pos], s[pos] + v[pos]});
        else seg.set(pos, e());
    };
    for (const auto & [op, i, x] : query) {
        if (op == 1) {
            int idx{get(B[i])};
            s[idx] += x - A[i];
            A[i] = x;
            upd(idx);
        } else {
            int old{get(B[i])};
            s[old] -= A[i];
            upd(old);
            B[i] = x;
            int nw{get(x)};
            s[nw] += A[i];
            upd(nw);
        }
       cout << seg.all_prod().max << "\n";
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}