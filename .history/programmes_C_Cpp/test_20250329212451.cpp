#include <iostream>
#include <vector>
using namespace std;
 
const long long MOD = 998244353;
 
// 计算 n 的阶乘并取模，这里用于计算小的 binom (n<=K<=10)
long long modMul(long long a, long long b) {
    return (a % MOD) * (b % MOD) % MOD;
}
 
// 预计算组合数 binom[k][j] (0<=j<=k<=K)
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
 
    // 计算前缀和 P[0..N]，定义 P[0]=0
    vector<long long> P(N+1, 0);
    P[0] = 0;
    for (int i = 1; i <= N; i++) {
        P[i] = (P[i-1] + A[i]) % MOD;
    }
 
    // 预计算所有 j 次幂的前缀累加 S_j(i)=sum_{l=0}^{i} (P[l])^j, 0<=j<=K, 0<=i<=N.
    // 注意：对于 j=0，我们定义 (P[l])^0 = 1 对于任意 l（包括 l=0）。
    vector<vector<long long>> cum(K+1, vector<long long>(N+1, 0));
    // j = 0: 每个 (P[l])^0 都为1
    for (int i = 0; i <= N; i++) {
        cum[0][i] = 1; // 1
    }
    // 对于 j>=1，从 i=0 开始
    for (int j = 1; j <= K; j++) {
        // 对于 i=0, P[0] = 0, 故 0^j = 0 （j>=1）
        cum[j][0] = 0;
        for (int i = 1; i <= N; i++) {
            // 计算 (P[i])^j（K<=10，直接循环计算即可）
            long long power = 1;
            for (int t = 0; t < j; t++) {
                power = modMul(power, P[i]);
            }
            cum[j][i] = (cum[j][i-1] + power) % MOD;
        }
    }
 
    // 预计算二项式系数 binom[K][j] , 0<=j<=K
    auto binom = precompute_binom(K);
 
    // 计算答案：对于每个 r=1..N，区间 [l, r] 的贡献为
    // sum_{j=0}^{K} (-1)^j * binom(K, j) * (P[r])^(K-j) * (cum[j][r-1])
    long long ans = 0;
    for (int r = 1; r <= N; r++) {
        // 预先计算各个 j 对应的 (P[r])^(K-j)
        // 注意 j 从0到K，所以指数为 K, K-1, ..., 0
        vector<long long> pr_power(K+1, 0);
        pr_power[0] = 1; // P[r]^0
        //可以先计算 P[r]^K，然后逐步除以 P[r]（注意模逆元），但由于K较小，可以直接计算
        for (int j = 0; j <= K; j++) {
            long long pwr = 1;
            int exp = K - j;
            for (int t = 0; t < exp; t++) {
                pwr = modMul(pwr, P[r]);
            }
            pr_power[j] = pwr;
        }
 
        for (int j = 0; j <= K; j++) {
            long long term = pr_power[j];
            term = modMul(term, binom[K][j]);
            // (-1)^j mod MOD
            if (j % 2 == 1) {
                term = (MOD - term) % MOD;
            }
            // 累加时需要乘以 cum[j][r-1]，即 sum_{l=0}^{r-1} P[l]^j
            term = modMul(term, cum[j][r-1]);
 
            ans = (ans + term) % MOD;
        }
    }
 
    cout << ans % MOD << "\n";
    return 0;
}
