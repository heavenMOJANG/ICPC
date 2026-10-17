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
    for (auto [key, val] : views::enumerate(s))
        if (val) to_seg[key] = {val, val + v[key]};
        else to_seg[key] = e();
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}