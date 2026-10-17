#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, K; cin >> N >> K;
    vector<vector<int>> A(N);
    vector<int> L(N);
    for (int i{}; i < N; ++ i) {
        cin >> L[i];
        A[i].resize(L[i]);
        for (int j{}; j < L[i]; ++ j) cin >> A[i][j];
    }
    vector<int> C(N);
    for (int i{}; i < N; ++ i) cin >> C[i];
    for (int i{}; i < N; ++ i) {
        int res = C[i] * L[i];
        if (K <= res) {
            int idx = (K - 1) % L[i];
            cout << A[i][idx] << "\n";
            return;
        } else K -= res;
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}
