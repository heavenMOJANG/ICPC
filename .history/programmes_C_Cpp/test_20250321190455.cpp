#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 998244353;

// 计算满足 0 <= b_i <= L 且 b_i 是 a 的二进制子集的数量
long long countSubsets(long long a, long long L) {
    if (L < 0) return 0;
    
    // 将 a 和 L 转为二进制位数组（最多 64 位）
    vector<int> bitsA(64, 0);
    vector<int> bitsL(64, 0);
    for (int i = 0; i < 64; ++i) {
        if (a & (1LL << i)) bitsA[i] = 1;
        if (L & (1LL << i)) bitsL[i] = 1;
    }
    
    // dp[pos][tight]：从 pos 位到低位的方案数
    vector<vector<long long>> dp(64, vector<long long>(2, 0));
    dp[63][1] = 1; // 初始状态
    
    // 从高位到低位处理
    for (int pos = 63; pos >= 0; --pos) {
        for (int tight = 0; tight < 2; ++tight) {
            if (dp[pos][tight] == 0) continue;
            int upper = tight ? bitsL[pos] : 1; // 当前位的上界
            for (int d = 0; d <= upper; ++d) {
                // 如果取 1，必须 a 的对应位为 1
                if (d == 1 && bitsA[pos] == 0) continue;
                int new_tight = tight && (d == upper);
                int next_pos = pos - 1;
                if (next_pos >= 0) {
                    dp[next_pos][new_tight] = (dp[next_pos][new_tight] + dp[pos][tight]) % MOD;
                } else {
                    dp[0][new_tight] = (dp[0][new_tight] + dp[pos][tight]) % MOD;
                }
            }
        }
    }
    
    return (dp[0][0] + dp[0][1]) % MOD;
}

int main() {
    int n;
    cin >> n;
    vector<long long> a(n), L(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> L[i];
    }
    
    long long ans = 1;
    for (int i = 0; i < n; ++i) {
        long long cnt = countSubsets(a[i], L[i]);
        ans = (ans * cnt) % MOD;
    }
    
    cout << ans << endl;
    return 0;
}