#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int G = 3;  // Primitive root modulo MOD

// Modular exponentiation: computes a^e % MOD
long long modpow(long long a, long long e) {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

// Iterative NTT (Number Theoretic Transform) implementation
void ntt(vector<int>& a, bool invert) {
    int n = (int)a.size();
    
    // Bit-reversal permutation
    static vector<int> rev;
    if ((int)rev.size() != n) {
        int k = __builtin_ctz(n);
        rev.assign(n, 0);
        for (int i = 0; i < n; i++) {
            rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));
        }
    }
    for (int i = 0; i < n; i++) {
        if (i < rev[i]) swap(a[i], a[rev[i]]);
    }
    
    // Precompute roots of unity
    static vector<int> roots{0, 1};
    if ((int)roots.size() < n) {
        int k = __builtin_ctz(roots.size());
        roots.resize(n);
        while ((1 << k) < n) {
            long long z = modpow(G, (MOD - 1) >> (k + 1));
            for (int i = 1 << (k - 1); i < (1 << k); ++i) {
                roots[2 * i] = roots[i];
                roots[2 * i + 1] = (long long)roots[i] * z % MOD;
            }
            ++k;
        }
    }
    
    // Butterfly operation
    for (int len = 1; len < n; len <<= 1) {
        for (int i = 0; i < n; i += 2 * len) {
            for (int j = 0; j < len; ++j) {
                int u = a[i + j];
                int v = (long long)a[i + j + len] * roots[len + j] % MOD;
                int x = (u + v) % MOD;
                int y = (u - v + MOD) % MOD;
                a[i + j] = x;
                a[i + j + len] = y;
            }
        }
    }
    
    // Inverse NTT
    if (invert) {
        reverse(a.begin() + 1, a.end());
        long long inv_n = modpow(n, MOD - 2);
        for (int i = 0; i < n; i++) {
            a[i] = (long long)a[i] * inv_n % MOD;
        }
    }
}

// Polynomial multiplication using NTT
vector<int> multiply(const vector<int>& a, const vector<int>& b) {
    if (a.empty() || b.empty()) return {};
    
    int need = (int)a.size() + (int)b.size() - 1;
    int n = 1;
    while (n < need) n <<= 1;
    
    vector<int> fa(a.begin(), a.end());
    vector<int> fb(b.begin(), b.end());
    fa.resize(n);
    fb.resize(n);
    
    ntt(fa, false);
    ntt(fb, false);
    
    for (int i = 0; i < n; i++) {
        fa[i] = (long long)fa[i] * fb[i] % MOD;
    }
    
    ntt(fa, true);
    fa.resize(need);
    return fa;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    if (!(cin >> N >> M)) return 0;
    
    vector<int> A(N), B(M);
    int maxA = 0, maxB = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        maxA = max(maxA, A[i]);
    }
    for (int j = 0; j < M; j++) {
        cin >> B[j];
        maxB = max(maxB, B[j]);
    }
    
    int V = max(maxA, maxB);
    int L = maxB + 1;  // Length for countsB
    
    // Frequency counts
    vector<int> countsA(V + 1, 0), countsB(L, 0);
    for (int x : A) countsA[x] += 1;
    for (int x : B) countsB[x] += 1;
    
    // Precompute factorials and inverse factorials up to V
    vector<int> fact(V + 1), invfact(V + 1);
    fact[0] = 1;
    for (int i = 1; i <= V; i++) {
        fact[i] = (long long)fact[i - 1] * i % MOD;
    }
    invfact[V] = modpow(fact[V], MOD - 2);
    for (int i = V; i > 0; i--) {
        invfact[i - 1] = (long long)invfact[i] * i % MOD;
    }
    
    // Prepare polynomials for convolution: U[k] = countsB[k] * k!
    // Vr is reversed invfact for convolution (effectively sum countsB[k] / (k + x)! * x! or similar)
    vector<int> U(L), Vr(L);
    for (int i = 0; i < L; i++) {
        U[i] = (long long)countsB[i] * fact[i] % MOD;
        Vr[L - 1 - i] = invfact[i];
    }
    
    // Compute convolution: conv[idx] corresponds to coefficients for sum over k + x = idx - (L-1)
    vector<int> conv = multiply(U, Vr);
    
    // Compute the final answer
    long long ans = 0;
    for (int x = 0; x <= maxA; x++) {
        int idx = (L - 1) + x;
        long long T = 0;
        if (idx < (int)conv.size()) {
            T = conv[idx];
        }
        // s[x] = T * invfact[x] % MOD  (which is the sum over k of countsB[k] * binom(k + x, x))
        long long sx = T * invfact[x] % MOD;
        ans = (ans + sx * countsA[x]) % MOD;
    }
    
    cout << ans << "\n";
    return 0;
}