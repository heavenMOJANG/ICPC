#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, Q; cin >> N >> Q;
    vector<int> A(N + 2, 500000);
    A[0] = 0;
    for (int i : views::iota(1, N + 1)) {
        int op; cin >> op;
        if (op == 1) {
            int x; cin >> x;
            A[x] ++;
            A[x + 1] --;
        } else {
            A[1] --;
            A[N + 1] ++;
        }
    }
    int ans{};
    for (int i : views::iota(1, N + 1)) {
        A[i] += A[i - 1];
        if (A[i] > 500000) ans ^= A[i] - 500000;
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}