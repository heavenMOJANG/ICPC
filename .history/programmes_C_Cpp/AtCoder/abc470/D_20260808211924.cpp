#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, Q; cin >> N >> Q;
    vector<int> P(N + 1), R(N + 1);
    for (int i : views::iota(1, N + 1)) cin >> P[i], R[P[i]] = i;
    while (Q --) {
        int op; cin >> op;
        if (op == 1) {
            int x, y; cin >> x >> y;
            swap(P[x], R[y]);
            R[P[x]] = x;
            R[P[y]] = y;
        } else swap(P, R);
    }
    for (int i : views::iota(1, N + 1)) cout << P[i] << " \n"[i == N];
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}