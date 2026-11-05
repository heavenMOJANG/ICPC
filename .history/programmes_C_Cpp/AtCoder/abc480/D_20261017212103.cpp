#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, Q; cin >> N >> Q;
    vector<int> P(N + 1), PP(N + 1), C(N + 1);
    for (int i : views::iota(1, N + 1)) {
        int A; cin >> A;
        P[i] = P[i - 1] + A;
        PP[i] = PP[i - 1] + P[i];
        C[i] = C[i - 1] + i;
    }
    auto f = [&](int x) ->int {
        if (x == 0) return 0;
        int pos{lower_bound(C.begin(), C.end(), x) - C.begin()};
        int res{x - C[pos - 1]};
        return PP[pos - 1] + P[res];
    };
    while (Q --) {
        int L, R; cin >> L >> R;
        cout << f(R) - f(L - 1) << "\n";
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}