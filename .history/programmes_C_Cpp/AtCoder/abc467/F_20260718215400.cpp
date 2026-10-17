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
    for (int i{1}; i <= N; ++ i) v.emplace_back(B[i]);
    for (auto && [op, i, x] : query) {
        cin >> op >> i >> x;
        if (op == 2) v.emplace_back(x);
    }
    ranges::sort(v);
    v.erase(unique(v.begin(), v.end()), v.end());
    auto get = [&](int x) { return lower_bound(v.begin(),) - v.begin();};
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}