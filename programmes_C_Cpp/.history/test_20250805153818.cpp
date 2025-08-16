#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// 使用 long long 防止乘法溢出
using ll = long long;

// 定义模数和矩阵维度
const int MOD = 998244353;
const int MAT_SIZE = 18;

// 矩阵结构体
struct Matrix {
    ll mat[MAT_SIZE][MAT_SIZE];

    Matrix() {
        for (int i = 0; i < MAT_SIZE; ++i) {
            for (int j = 0; j < MAT_SIZE; ++j) {
                mat[i][j] = 0;
            }
        }
    }
};

// 矩阵乘法
Matrix multiply(const Matrix& a, const Matrix& b) {
    Matrix result;
    for (int i = 0; i < MAT_SIZE; ++i) {
        for (int j = 0; j < MAT_SIZE; ++j) {
            for (int k = 0; k < MAT_SIZE; ++k) {
                result.mat[i][j] = (result.mat[i][j] + a.mat[i][k] * b.mat[k][j]) % MOD;
            }
        }
    }
    return result;
}

// 矩阵快速幂
Matrix matrix_pow(Matrix base, ll exp) {
    Matrix result;
    // 初始化为单位矩阵
    for (int i = 0; i < MAT_SIZE; ++i) {
        result.mat[i][i] = 1;
    }
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = multiply(result, base);
        }
        base = multiply(base, base);
        exp /= 2;
    }
    return result;
}

// 模幂运算 (用于计算模逆元)
ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

// 计算模逆元
ll modInverse(ll n) {
    return power(n, MOD - 2);
}

void solve() {
    ll n;
    int k;
    cin >> n >> k;
    vector<int> D(k);
    ll sum_d = 0;
    for (int i = 0; i < k; ++i) {
        cin >> D[i];
        sum_d += D[i];
    }

    ll inv_k = modInverse(k);
    ll E_d = (sum_d % MOD * inv_k) % MOD;

    // 如果 n=1，答案就是单个数字的期望值
    if (n == 1) {
        cout << E_d << endl;
        return;
    }

    // --- 构建转移矩阵 M ---
    Matrix M;
    ll inv_5 = modInverse(5);

    // 第 0 行 (E_n 的递推)
    // E_n = E_{n-1} * (E_d+3)/5 + 3*E_d/5 - 2/5 * E[v_{n-1} & d]
    M.mat[0][0] = ((E_d + 3) % MOD * inv_5) % MOD; // E_{n-1} 的系数
    M.mat[0][17] = ((3 * E_d) % MOD * inv_5) % MOD; // 常数项的系数
    
    ll D_const = (2 * inv_5 % MOD * inv_k % MOD);
    vector<ll> W(16);
    for (int j = 0; j < 16; ++j) {
        ll sum_jd = 0;
        for (int d : D) {
            sum_jd += (j & d);
        }
        W[j] = sum_jd % MOD;
        // E[v & d] = sum(p(j) * (sum(j&d)/k))
        // p_{n-1}(j) 的系数
        M.mat[0][j + 1] = (MOD - (D_const * W[j]) % MOD) % MOD; 
    }

    // 第 1-16 行 (p_n(j) 的递推)
    for (int l = 0; l < 16; ++l) { // l = v_{i-1} % 16
        vector<ll> counts(16, 0);
        for (int d : D) {
            counts[(l + d) % 16]++;
            counts[(l * d) % 16]++;
            counts[(l & d)]++;
            counts[(l | d)]++;
            counts[(l ^ d)]++;
        }
        for (int j = 0; j < 16; ++j) { // j = v_i % 16
            // P(v_i%16=j | v_{i-1}%16=l) = counts[j] / (5*k)
            M.mat[j + 1][l + 1] = (counts[j] * inv_5 % MOD * inv_k % MOD);
        }
    }

    // 第 17 行 (常数 1 的递推)
    M.mat[17][17] = 1;

    // --- 计算 M^(n-1) ---
    Matrix M_pow = matrix_pow(M, n - 1);

    // --- 构建初始状态向量 V1 ---
    vector<ll> V1(MAT_SIZE, 0);
    V1[0] = E_d; // E_1
    
    vector<ll> p1_counts(16, 0);
    for (int d : D) {
        p1_counts[d % 16]++;
    }
    for (int j = 0; j < 16; ++j) {
        V1[j + 1] = (p1_counts[j] * inv_k) % MOD; // p_1(j)
    }
    V1[17] = 1; // 常数项

    // --- 最终计算 V_n = M^(n-1) * V_1 ---
    ll E_n = 0;
    // 只需计算结果向量的第一个元素 E_n
    for (int j = 0; j < MAT_SIZE; ++j) {
        E_n = (E_n + M_pow.mat[0][j] * V1[j]) % MOD;
    }

    cout << E_n << endl;
}

int main() {
    // 加速 C++ I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}