#include <bits/stdc++.h>
using namespace std;

static const int MOD = 998244353;

long long mod_pow(long long a, long long e) {
    long long r = 1 % MOD;
    a %= MOD;
    while (e > 0) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

struct Fenwick {
    int n;
    vector<long long> bit;
    Fenwick(int n=0): n(n), bit(n+1, 0) {}
    void add(int i, long long v) {
        for (; i <= n; i += i & -i) {
            bit[i] += v;
            if (bit[i] >= MOD || bit[i] <= -MOD) bit[i] %= MOD;
        }
    }
    long long sumPrefix(int i) const {
        long long r = 0;
        for (; i > 0; i -= i & -i) {
            r += bit[i];
            if (r >= MOD || r <= -MOD) r %= MOD;
        }
        r %= MOD;
        if (r < 0) r += MOD;
        return r;
    }
    long long sumRange(int l, int r) const {
        if (l > r) return 0;
        long long res = sumPrefix(r) - sumPrefix(l - 1);
        res %= MOD;
        if (res < 0) res += MOD;
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> P(N + 1);
    for (int i = 1; i <= N; i++) cin >> P[i];

    // precompute powers of 2 and inverse powers
    vector<long long> pow2(N + 1), invpow2(N + 1);
    pow2[0] = 1;
    for (int i = 1; i <= N; i++) pow2[i] = (pow2[i - 1] * 2) % MOD;

    long long inv2 = mod_pow(2, MOD - 2);
    invpow2[0] = 1;
    for (int i = 1; i <= N; i++) invpow2[i] = (invpow2[i - 1] * inv2) % MOD;

    // Step 1: compute C[j] and F[j]
    Fenwick bitCnt(N); // counts of values
    vector<long long> F(N + 1, 0);

    long long S = 0; // S = sum_{t<j} C[t] * 2^{-t}
    for (int j = 1; j <= N; j++) {
        long long Cj = bitCnt.sumPrefix(P[j] - 1); // number of i<j with P[i]<P[j]
        long long Fj = (Cj + pow2[j - 1] * S) % MOD;
        F[j] = Fj;

        S = (S + Cj * invpow2[j]) % MOD;
        bitCnt.add(P[j], 1);
    }

    // Step 2: weighted inversions by value: sum_{l<m, P[l]>P[m]} F[l]
    Fenwick bitW(N);
    long long ans = 0;
    for (int m = 1; m <= N; m++) {
        long long greater = (bitW.sumPrefix(N) - bitW.sumPrefix(P[m])) % MOD;
        if (greater < 0) greater += MOD;
        ans = (ans + greater) % MOD;

        bitW.add(P[m], F[m]);
    }

    cout << ans % MOD << "\n";
    return 0;
}
