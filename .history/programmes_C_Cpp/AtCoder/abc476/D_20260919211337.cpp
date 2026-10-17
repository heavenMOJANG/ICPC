#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, M, K, X, Y; cin >> N >> M >> K >> X >> Y;
    vector<int> A(N), B(M);
    for (auto && x : A) cin >> x;
    for (auto && x : B) cin >> x;
    ranges::sort(A);
    ranges::sort(B);
    vector<int> pA(N + 1, 0);
    for (int i : views::iota(0, N)) pA[i + 1] = pA[i] + A[i];
    vector<int> pB(M + 1, 0), rB(M + 1, 0);
    for (int i : views::iota(0, M)) pB[i + 1] = pB[i] + B[i], rB[i + 1] = rB[i] + (B[i] + K - 1) / K;
    int tot{X + K * Y}, ans{};
    for (int i : views::iota(0, M + 1)) {
        if (rB[i] > Y) break;
        if (pB[i] > tot) break;
        int res{tot - pB[i]}, p{ranges::upper_bound(pA, res) - A.begin() - 1};
        ans = max(ans, p + i);
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