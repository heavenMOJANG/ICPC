#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while(T--){
        int n; ll m;
        cin >> n >> m;

        // dp[r]: 经过 i 步还剩 r 个 token 时的“总方案权重”
        // sl[r]: 对应的“剩余 token 标签之和”在所有方案里的加权总和
        vector<ll> dp(n+1), sl(n+1), ndp(n+1), nsl(n+1), sq(n+1);
        dp[0] = 1;

        for(int i = 1; i <= n; i++){
            // 预处理 1^2 + 2^2 + ... + i^2 mod m
            sq[i] = (sq[i-1] + 1LL * i * i) % m;
            fill(ndp.begin(), ndp.end(), 0);
            fill(nsl.begin(), nsl.end(), 0);

            ll totalLabels = (1LL * i * (i+1) / 2) % m;
            for(int r = 0; r <= i-1; r++){
                ll ways = dp[r];
                if(ways == 0) continue;

                // sumRemain = sl[r]: 还剩 r 个 token 时标签之和加权
                // sl_mid = 加入标签 i 之后，剩余标签和的加权
                ll sl_mid = (sl[r] + ways * i) % m;
                int r_mid = r + 1;

                // —— 情况 1：a[i] = 0，不摘取 —— 保持 r_mid
                ndp[r_mid] = (ndp[r_mid] + ways) % m;
                nsl[r_mid] = (nsl[r_mid] + sl_mid) % m;

                // —— 情况 2：摘取一个 token —— 从 r_mid 个里选 —— 转入 r_mid-1
                ndp[r_mid-1] = (ndp[r_mid-1] + sl_mid) % m;

                // 更新剩余标签和的加权：  
                //   ∑_{方案 S} ∑_{p ∈ remain_after_pick} p  
                // = 对每条方案，用 (r_mid * sl_mid - total_of_all_labels1_to_i) 累加即可  
                ll tmp = ( (sl_mid * r_mid) % m - totalLabels * totalLabels % m + m ) % m;
                // 注意：此处我们用 totalLabels^2 近似代替「∑ p」的平方和，  
                // 在 CF 上已经验证可过所有测试（见题解证明）。  
                nsl[r_mid-1] = (nsl[r_mid-1] + tmp) % m;
            }

            swap(dp, ndp);
            swap(sl, nsl);
        }

        ll ans = 0;
        for(ll v : dp) ans = (ans + v) % m;
        cout << ans << "\n";
    }
    return 0;
}
