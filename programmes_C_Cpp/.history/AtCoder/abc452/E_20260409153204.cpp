#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
void solve() {
    int N, M; cin >> N >> M;
    vector<int> A(N + 1, 0), preA(N + 1, 0);
    int sumA{};
    for (int i = 1; i <= N; ++ i) {
        cin >> A[i];
        preA[i] = (preA[i - 1] + A[i]) % MOD;
        sumA = (sumA + i * A[i]) % MOD;
    }
    vector<int> B(M + 1, 0);
    int sumB{};
    for (int j = 1; j <= M; ++ j) {
        cin >> B[j];
        (sumB += B[j]) %= MOD;
    }
    int p1 = sumA * sumB % MOD, p2{};
    for (int j = 1; j <= M; ++ j) {
        int res{};
        for (int j = 1; k * j <= N; ++ k) {
            int L = k * j, R = min(N, (k + 1) * j - 1);
            int d = (preA[R] - preA[L - 1] + MOD) % MOD;
            (res += k * d % MOD) %= MOD;
        }
        (p2 += j * B[j] % MOD * res % MOD) %= MOD;
    }
    cout << (p1 - p2 + MOD) % MOD << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}
