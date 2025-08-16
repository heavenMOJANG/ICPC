#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
constexpr int MAT_SIZE = 18;
struct MATRIX {
    int mat[MAT_SIZE][MAT_SIZE];
    MATRIX () { for (int i{}; i < MAT_SIZE; ++ i) fill(mat[i], mat[i] + MAT_SIZE, 0); }
    friend MATRIX operator * (const MATRIX& A, const MATRIX& B) {
        MATRIX R;
        for (int i{}; i < MAT_SIZE; ++ i)
            for (int j{}; j < MAT_SIZE; ++ j)
                for (int k{}; k < MAT_SIZE; ++ k)
                    (R.mat[i][j] += A.mat[i][k] * B.mat[k][j]) %= MOD;
        return R;
    }
};
MATRIX mpow(MATRIX B, int x) {
    MATRIX R;
    for (int i{}; i < MAT_SIZE; ++ i) R.mat[i][i] = 1;
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
int getInv(int x) { return qpow(x, MOD - 2); }
void solve() {
    int n, k; cin >> n >> k;
    vector<int> D(k);
    int sum{};
    for (auto && x : D) cin >> x, sum += x;
    int INV_K = getInv(k), E_D = sum * INV_K % MOD;
    if (n == 1) { cout << E_D << "\n"; return; }
    MATRIX M;
    int INV_5 = getInv(5);
    M.mat[0][0] = ((E_D + 3) % MOD * INV_5) % MOD;
    M.mat[0][17] = E_D * 3 % MOD * INV_5 % MOD;
    int DD = INV_5 * 2 % MOD * INV_K % MOD;
    vector<int> W(16);
    for (int i{}; i < 16; ++ i) {
        int tmp{};
        for (int d : D) tmp += i & d;
        W[i] = tmp;
        M.mat[0][i + 1] = (MOD - DD * W[i] % MOD) % MOD;
    }
    for (int col{}; col < 16; ++ col) {
        vector<int> cnt(16, 0);
        for (int d : D) {
            cnt[(col + d) % 16] ++;
            cnt[(col * d) % 16] ++;
            cnt[col & d] ++;
            cnt[col | d] ++;
            cnt[col ^ d] ++;
        }
        for (int i{}; i < 16; ++ i)
            M.mat[i + 1][col + 1] = cnt[i] * INV_5 % MOD * INV_K % MOD;
    }
    M.mat[17][17] = 1;
    MATRIX P = mpow(M, n - 1);
    vector<int> V(MAT_SIZE, 0);
    V[0] = E_D;
    vector<int> cnt(16, 0);
    for (int d : D) cnt[d % 16] ++;
    for (int i{}; i < 16; ++ i) V[i + 1] = cnt[i] * INV_K % MOD;
    V[17] = 1;
    int ans = 0;
    for (int i{}; i < MAT_SIZE; ++ i) (ans += P.mat[0][i] * V[i] % MOD) %= MOD;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}