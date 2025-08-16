#include <bits/stdc++.h>
using namespace std;
static const int MOD = 998244353;

// 快速幂
long long modpow(long long a, long long e=MOD-2) {
    long long r = 1;
    while (e) {
        if (e&1) r = r*a % MOD;
        a = a*a % MOD;
        e >>= 1;
    }
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,long long>>> byR(m+1);
    // 存 (l_i, w_i) 放到 byR[r_i]
    long long base = 1;
    for(int i = 0; i < n; i++){
        int l, r;
        long long p, q;
        cin >> l >> r >> p >> q;
        // 计算 (q-p)/q mod
        long long invq = modpow(q);
        long long one_minus_ri = (q - p) % MOD * invq % MOD;
        if (one_minus_ri < 0) one_minus_ri += MOD;
        base = base * one_minus_ri % MOD;

        // 计算 w_i = (p/q)/(1-p/q) = p/(q-p) mod
        long long denom = (q - p) % MOD;
        if (denom < 0) denom += MOD;
        long long wi = p % MOD * modpow(denom) % MOD;

        byR[r].emplace_back(l, wi);
    }

    // dp[j]：覆盖 [1,j] 的方案权重和
    vector<long long> dp(m+1, 0);
    dp[0] = 1;
    for(int j = 1; j <= m; j++){
        long long sum = 0;
        for(auto &seg : byR[j]){
            int l = seg.first;
            long long wi = seg.second;
            sum = (sum + wi * dp[l-1]) % MOD;
        }
        dp[j] = sum;
    }

    long long S = dp[m];
    long long ans = base * S % MOD;
    cout << ans << "\n";
    return 0;
}
