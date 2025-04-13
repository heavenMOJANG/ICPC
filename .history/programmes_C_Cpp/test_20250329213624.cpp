#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 998244353;

// 快速乘法（由于K较小，也可直接用循环乘）
long long modMul(long long a, long long b) {
    return (a % MOD) * (b % MOD) % MOD;
}

// 预计算二项式系数 binom[i][j] (0<=j<=i<=K)
vector<vector<long long>> precompute_binom(int K) {
    vector<vector<long long>> binom(K+1, vector<long long>(K+1, 0));
    for (int i = 0; i <= K; i++) {
        binom[i][0] = 1;
        binom[i][i] = 1;
        for (int j = 1; j < i; j++) {
            binom[i][j] = (binom[i-1][j-1] + binom[i-1][j]) % MOD;
        }
    }
    return binom;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<long long> A(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    
    // 计算前缀和 P[0..N] (1-indexed, P[0]=0)
    vector<long long> P(N+1, 0);
    P[0] = 0;
    for (int i = 1; i <= N; i++) {
        P[i] = (P[i-1] + A[i]) % MOD;
    }
    
    // 对于每个 j=0..K，预计算 Cum[j][i] = sum_{l=0}^{i} (P[l])^j, 0<=i<=N.
    // 注意：对于 j = 0, 定义 (P[l])^0 = 1（包括 l = 0）。
    vector<vector<long long>> Cum(K+1, vector<long long>(N+1, 0));
    // j=0
    for (int i = 0; i <= N; i++) {
        Cum[0][i] = 1; // 因为1累加
    }
    // j>=1
    for (int j = 1; j <= K; j++) {
        Cum[j][0] = 0; // P[0]=0, 对于 j>=1，0^j=0
        for (int i = 1; i <= N; i++) {
            long long power = 1;
            // 计算 (P[i])^j （由于 j<=10，可以用循环）
            for (int t = 0; t < j; t++) {
                power = modMul(power, P[i]);
            }
            Cum[j][i] = (Cum[j][i-1] + power) % MOD;
        }
    }
    
    // 预计算二项式系数
    auto binom = precompute_binom(K);
    
    // 最终答案 = sum_{r=1}^{N} sum_{j=0}^{K} (-1)^j * binom[K][j] * (P[r])^(K-j) * Cum[j][r-1]
    long long ans = 0;
    for (int r = 1; r <= N; r++) {
        // 对于固定 r，P[r] 已知
        // 对于 j=0..K，计算 (P[r])^(K-j)
        // 由于指数最大为K，直接用循环即可
        for (int j = 0; j <= K; j++) {
            int exp = K - j;
            long long pwr = 1;
            for (int t = 0; t < exp; t++) {
                pwr = modMul(pwr, P[r]);
            }
            long long term = pwr;
            term = modMul(term, binom[K][j]); // 乘上二项式系数
            if(j & 1) { // 如果 j 为奇数，加上负号
                term = (MOD - term) % MOD;
            }
            // 累加时乘以 Cum[j][r-1] = sum_{l=0}^{r-1} (P[l])^j
            term = modMul(term, Cum[j][r-1]);
            ans = (ans + term) % MOD;
        }
    }
    
    cout << ans % MOD << "\n";
    return 0;
}
