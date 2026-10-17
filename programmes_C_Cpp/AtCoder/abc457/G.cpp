#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct Node { int a, b; };
void solve() {
    int N; cin >> N;
    vector<Node> A(N);
    for (int i{}; i < N; ++ i) {
        int T, X; cin >> T >> X;
        A[i].a = T - X;
        A[i].b = T + X;
    }
    sort(A.begin(), A.end(), [](const Node& x, const Node& y) {
        return x.a != y.a ? x.a < y.a : x.b < y.b;
    });
    vector<int> dp;
    for (int i{}; i < N; ++ i) {
        auto [a, b] = A[i];
        auto it = lower_bound(dp.begin(), dp.end(), b, greater<int>());
        if (it == dp.end()) dp.emplace_back(b);
        else *it = b;
    }
    cout << dp.size() << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}
