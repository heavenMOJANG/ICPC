#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int64 L, R;
    cin >> L >> R;
    int64 N = R - L + 1;
    
    // 1. 筛出 <= sqrt(R) 的素数
    int64 S = floor(sqrt((long double)R));
    vector<char> is_prime_small(S + 1, true);
    is_prime_small[0] = is_prime_small[1] = false;
    for (int64 i = 2; i * i <= S; i++) {
        if (is_prime_small[i]) {
            for (int64 j = i * i; j <= S; j += i) {
                is_prime_small[j] = false;
            }
        }
    }
    vector<int> small_primes;
    for (int i = 2; i <= S; i++) {
        if (is_prime_small[i]) small_primes.push_back(i);
    }

    // 2. 分段筛 [L..R] 标记素数
    vector<char> is_prime_seg(N, true);
    if (L == 1) is_prime_seg[0] = false;
    for (int p : small_primes) {
        int64 start = max((int64)p * p, ((L + p - 1) / p) * p);
        for (int64 x = start; x <= R; x += p) {
            is_prime_seg[x - L] = false;
        }
    }

    // 3. 标记所有素数和素数幂
    vector<char> is_special(N, false);
    // 3.1 素数 (p^1)
    for (int64 i = 0; i < N; i++) {
        if (is_prime_seg[i]) is_special[i] = true;
    }
    // 3.2 素数高次幂 p^k (k >= 2)
    for (int p : small_primes) {
        __int128 x = ( (__int128)p ) * p;  // k = 2
        while (x <= R) {
            if (x >= L) {
                is_special[(int64)(x - L)] = true;
            }
            x *= p;
        }
    }

    // 4. 统计特征点数：只统计 (L, R] 范围内的 prime power
    int64 M = 0;
    for (int64 i = 1; i < N; i++) {
        if (is_special[i]) M++;
    }
    // +1 对应 A_L
    cout << (M + 1) << '\n';
    return 0;
}
