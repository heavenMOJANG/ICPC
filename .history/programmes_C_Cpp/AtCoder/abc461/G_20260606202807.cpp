#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
#define int long long
using namespace std;
using namespace atcoder;
using S = int;
constexpr int INF = 0x7fffffff;
S op(int a, int b) { return a + b; }
S e() { return 0ll; }
void solve() {
    int N, Q; cin >> N >> Q;
    int T = Q + 1;
    vector<int> R(N + 1, 0), C = R;
    fenwick_tree<int> fr(T), fc(T);
    fr.add(0, N); fc.add(0, N);
    int cur{};
    for (int i{1}; i <= Q; ++ i) {

    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}