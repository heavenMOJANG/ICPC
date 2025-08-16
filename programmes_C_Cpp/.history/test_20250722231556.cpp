#include <bits/stdc++.h>
using namespace std;
static const int MOD = 998244353;
using ll = long long;

// 快速幂（求逆元用）
ll modpow(ll a, ll e = MOD-2) {
    ll r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

struct Seg {
    int l, r;
    ll w;  // 权重 w_i = p/(q-p) mod
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Seg> segs;
    segs.reserve(n);
    ll base = 1;

    for (int i = 0; i < n; i++) {
        ll l, r, p, q;
        cin >> l >> r >> p >> q;
        // 累积 (1 - r_i) = (q-p)/q
        base = base * ((q - p) % MOD * modpow(q) % MOD) % MOD;

        // 计算 w_i = (p/q) / (1 - p/q) = p/(q-p)
        ll denom = (q - p) % MOD;
        if (denom < 0) denom += MOD;
        ll wi = p % MOD * modpow(denom) % MOD;

        segs.push_back({int(l), int(r), wi});
    }

    // 按右端点升序
    sort(segs.begin(), segs.end(), [](auto &a, auto &b){ return a.r < b.r; });

    vector<ll> dp(m+1);
    dp[0] = 1;

    int idx = 0;
    // 扫描每个位置 j，处理所有 r==j 的段
    for (int j = 1; j <= m; j++) {
        ll sum = 0;
        while (idx < n && segs[idx].r == j) {
            auto &S = segs[idx++];
            sum = (sum + S.w * dp[S.l - 1]) % MOD;
        }
        dp[j] = sum;
    }

    // 最终答案 = base * dp[m]
    ll ans = base * dp[m] % MOD;
    if (ans < 0) ans += MOD;
    cout << ans << "\n";
    return 0;
}
