#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n;
        ll m;
        cin >> n >> m;
        // dp[r]: 权重和； sl[r]: 权重加权的剩余标签总和
        vector<ll> dp(n+1), sl(n+1), ndp(n+1), nsl(n+1), sq(n+1);
        dp[0] = 1;

        for(int i = 1; i <= n; i++){
            // 预处理 1^2 + ... + i^2 mod m
            sq[i] = (sq[i-1] + 1LL*i*i) % m;
            fill(ndp.begin(), ndp.end(), 0);
            fill(nsl.begin(), nsl.end(), 0);

            for(int r = 0; r < i; r++){
                ll ways = dp[r];
                if(!ways) continue;
                ll cursl = sl[r];
                // 加入标签 i 后的新 sl
                ll sl_mid = (cursl + ways * i) % m;
                int r_mid = r + 1;

                // 情况 1：跳过 → 状态 (r_mid)
                ndp[r_mid] = (ndp[r_mid] + ways) % m;
                nsl[r_mid] = (nsl[r_mid] + sl_mid) % m;

                // 情况 2：拿走一个代币 → 状态 (r_mid-1)
                // dp 加权：每种方案有 sl_mid 种摘取方式
                ndp[r_mid-1] = (ndp[r_mid-1] + sl_mid) % m;
                // sum 转移：对于每一种方案，
                //   ∑_{p ∈ L}( sl_mid - p )
                // = r_mid*sl_mid - (∑ p)
                //  而 ∑ p = 前 i 个标签之和 - 已经被摘标签的平方和等复杂项
                // 最终简化可写成：
                ll tmp = ( (ll)r_mid * sl_mid % m
                           - (ll)i*(i+1)*(2ll*i+1)/6 % m
                           + m ) % m;
                nsl[r_mid-1] = (nsl[r_mid-1] + tmp) % m;
            }

            dp.swap(ndp);
            sl.swap(nsl);
        }

        ll ans = 0;
        for(ll v : dp) ans = (ans + v) % m;
        cout << ans << "\n";
    }
    return 0;
}
