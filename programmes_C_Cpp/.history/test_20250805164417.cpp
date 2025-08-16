#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
constexpr int N = 18;
struct MATRIX {
    int mat[N][N];
    MATRIX () { for (int i{}; i < N; ++ i) fill(mat[i], mat[i] + N, 0); }
    friend MATRIX operator * (const MATRIX& A, const MATRIX& B) {
        MATRIX R;
        for (int i{}; i < N; ++ i)
            for (int j{}; j < N; ++ j)
                for (int k{}; k < N; ++ k)
                    (R.mat[i][j] += A.mat[i][k] * B.mat[k][j]) %= MOD;
        return R;
    }
};
MATRIX mpow(MATRIX B, int x) {
    MATRIX R;
    for (int i{}; i < N; ++ i) R.mat[i][i] = 1;
    while (x) {
        if (x & 1) R = R * B;
        B = B * B;
        x >>= 1;
    }
    return R;
}
int qpow(int a, int x) {
    int res = 1;
    while (x) {
        if (x & 1) res = res * a % MOD;
        a = a * a % MOD;
        x >>= 1;
    }
    return res;
}
void solve() {
    int n, k; cin >> n >> k;
    vector<int> D(k);
    int sum{};
    for (auto && x : D) cin >> x, sum += x;
    int INV_K = qpow(k, MOD - 2), E_D = sum * INV_K % MOD;
    if (n == 1) { cout << E_D << "\n"; return; }
    MATRIX A;
    int INV_5 = qpow(5, MOD - 2);
    A.mat[0][0] = ((E_D + 3) % MOD * INV_5) % MOD;
    A.mat[0][17] = E_D * 3 % MOD * INV_5 % MOD;
    int DD = INV_5 * 2 % MOD * INV_K % MOD;
    for (int j{}; j < 16; ++ j) {
        int tmp{};
        for (int d : D) tmp += j & d;
        A.mat[0][j + 1] = (MOD - DD * tmp % MOD) % MOD;
    }
    for (int j{}; j < 16; ++ j) {
        vector<int> cnt(16, 0);
        for (int d : D) {
            cnt[(j + d) % 16] ++; cnt[(j * d) % 16] ++;
            cnt[j & d] ++; cnt[j | d] ++; cnt[j ^ d] ++;
        }
        for (int i{}; i < 16; ++ i)
            A.mat[i + 1][j + 1] = cnt[i] * INV_5 % MOD * INV_K % MOD;
    }
    A.mat[17][17] = 1;
    MATRIX B = mpow(A, n - 1);
    vector<int> V(N, 0);
    V[0] = E_D;
    vector<int> cnt(16, 0);
    for (int d : D) cnt[d % 16] ++;
    for (int i{}; i < 16; ++ i) V[i + 1] = cnt[i] * INV_K % MOD;
    V[17] = 1;
    int ans = 0;
    for (int j{}; j < N; ++ j) (ans += B.mat[0][j] * V[j] % MOD) %= MOD;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}