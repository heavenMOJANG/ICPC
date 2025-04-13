#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 998244353;

// Function to count the number of b_i such that 0 <= b_i <= L and b_i is a binary subset of a
long long countSubsets(long long a, long long L) {
    if (L < 0) return 0;
    
    // Convert a and L to binary bit vectors (up to 64 bits since a, L <= 10^18)
    vector<int> bitsA(64, 0);
    vector<int> bitsL(64, 0);
    for (int i = 0; i < 64; ++i) {
        if (a & (1LL << i)) bitsA[i] = 1;
        if (L & (1LL << i)) bitsL[i] = 1;
    }
    
    // DP[pos][tight]: number of ways to fill bits from pos downward
    // tight = 1 if we are still bounded by L, 0 otherwise
    vector<vector<long long>> dp(64, vector<long long>(2, 0));
    dp[63][1] = 1; // Initialize: start at the highest bit, tight = 1
    
    // Process each bit from most significant to least significant
    for (int pos = 63; pos >= 0; --pos) {
        for (int tight = 0; tight < 2; ++tight) {
            if (dp[pos][tight] == 0) continue;
            int upper = tight ? bitsL[pos] : 1; // Upper bound for current bit
            for (int d = 0; d <= upper; ++d) {
                // If d = 1, it must be allowed by a (i.e., bitsA[pos] must be 1)
                if (d == 1 && bitsA[pos] == 0) continue;
                int new_tight = tight && (d == upper);
                int next_pos = pos - 1;
                if (next_pos >= 0) {
                    dp[next_pos][new_tight] = (dp[next_pos][new_tight] + dp[pos][tight]) % MOD;
                } else {
                    // Reached the end (pos = 0), accumulate result
                    dp[0][new_tight] = (dp[0][new_tight] + dp[pos][tight]) % MOD;
                }
            }
        }
    }
    
    // Total result is the sum of dp[0][0] and dp[0][1]
    long long res = (dp[0][0] + dp[0][1]) % MOD;
    return res;
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
        // Since b_i must be a subset of a_i, cap L[i] at a[i]
        long long cnt = countSubsets(a[i], min(a[i], L[i]));
        ans = (ans * cnt) % MOD;
    }
    
    cout << ans << endl;
    return 0;
}