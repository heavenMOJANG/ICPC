#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, M; cin >> N >> M;
    vector<int> A(N), B(N);
    for (auto && x : A) cin >> x;
    for (auto && x : B) cin >> x;
    int L{2 * N - 1};
    vector<int> P(L), Q(L);
    for (int i : views::iota(0, N))
        for (int j : views::iota(0, N)) {
            int mul{A[i] * B[j] % M};
            P[i + j] += mul;
            Q[i - j + N - 1] += mul;
        }
    auto cal = [&](vector<int>& A) {
        vector<int> v(L);
        int sum{};
        for (int i : views::iota(0, L)) {
            sum += A[i];
            v[0] += i * A[i];
        }
        int pre{A[0]};
        for (int i : views::iota(0, L - 1)) {
            v[i + 1] = v[i] + 2 * pre - sum;
            pre += A[i + 1];
        }
        return v;
    };
    auto X{cal(P)}, Y{cal(Q)};
    int ans{};
    for (int i : views::iota(0, N))
        for (int j : views::iota(0, N))
            ans ^= (X[i + j] + Y[i - j + N - 1]) / 2 + i * N + j;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}