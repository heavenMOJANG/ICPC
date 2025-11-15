#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;
const int G = 3;
const int MAXA = 500010;
const int SZ = 1 << 20; // 1048576

ll modpow(ll b, ll e, ll mod) {
    ll r = 1;
    while (e) {
        if (e & 1) r = r * b % mod;
        b = b * b % mod;
        e >>= 1;
    }
    return r;
}

ll modinv(ll x, ll mod) {
    return modpow(x, mod - 2, mod);
}

void ntt(vector<ll>& a, bool inverse = false) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j >= bit; bit >>= 1) j -= bit;
        j += bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        ll wl = modpow(G, (MOD - 1) / len, MOD);
        if (inverse) wl = modinv(wl, MOD);
        for (int i = 0; i < n; i += len) {
            ll w = 1;
            for (int j = 0; j < len / 2; j++) {
                ll u = a[i + j], v = a[i + j + len / 2] * w % MOD;
                a[i + j] = (u + v) % MOD;
                a[i + j + len / 2] = (u - v + MOD) % MOD;
                w = w * wl % MOD;
            }
        }
    }
    if (inverse) {
        ll in = modinv(n, MOD);
        for (auto& x : a) x = x * in % MOD;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<ll> As(N);
    for (auto& x : As) cin >> x;
    vector<ll> Bs(M);
    for (auto& x : Bs) cin >> x;
    vector<ll> freqA(MAXA + 1, 0), freqB(MAXA + 1, 0);
    for (auto x : As) {
        if (x <= MAXA) freqA[x]++;
    }
    for (auto x : Bs) {
        if (x <= MAXA) freqB[x]++;
    }
    vector<ll> fact(MAXA + 1);
    vector<ll> invfact(MAXA + 1);
    fact[0] = 1;
    for (int i = 1; i <= MAXA; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    invfact[MAXA] = modinv(fact[MAXA], MOD);
    for (int i = MAXA - 1; i >= 0; i--) {
        invfact[i] = invfact[i + 1] * (i + 1) % MOD;
    }
    vector<ll> u(MAXA + 1);
    for (int x = 0; x <= MAXA; x++) {
        u[x] = freqA[x] * fact[x] % MOD;
    }
    vector<ll> vv(MAXA + 1);
    for (int z = 0; z <= MAXA; z++) {
        vv[z] = invfact[z];
    }
    auto urev = u;
    reverse(urev.begin(), urev.end());
    vector<ll> va(SZ, 0), vb(SZ, 0);
    for (int i = 0; i <= MAXA; i++) va[i] = vv[i];
    for (int i = 0; i <= MAXA; i++) vb[i] = urev[i];
    ntt(va);
    ntt(vb);
    for (int i = 0; i < SZ; i++) {
        va[i] = va[i] * vb[i] % MOD;
    }
    ntt(va, true);
    vector<ll> c(MAXA + 1, 0);
    for (int k = 0; k <= MAXA; k++) {
        int pos = MAXA - k;
        ll sk = va[pos];
        c[k] = sk * invfact[k] % MOD;
    }
    ll ans = 0;
    for (int k = 0; k <= MAXA; k++) {
        ans = (ans + c[k] * freqB[k] % MOD) % MOD;
    }
    cout << ans << '\n';
    return 0;
}