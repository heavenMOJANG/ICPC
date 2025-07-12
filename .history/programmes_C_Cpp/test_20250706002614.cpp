#pragma GCC optimize("Ofast","inline")
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

        // dp[k]    = 已做 k 次匹配的所有方案，权值之和
        // freeS[k] = 这些方案对应的「当前所有尚未被匹配的 token 标签之和」(乘以各自方案权值后累加)
        vector<ll> dp(n+1, 0), freeS(n+1, 0);
        vector<ll> ndp(n+1), nfreeS(n+1);

        dp[0] = 1;   // 0 步时，1 种空方案
        freeS[0] = 0;

        ll totSum = 0;  // 用来维护 (1+2+...+i) mod m
        for(int i = 1; i <= n; i++){
            totSum = (totSum + i) % m;

            // 清空下一行
            fill(ndp.begin(),    ndp.end(),    0);
            fill(nfreeS.begin(), nfreeS.end(), 0);

            for(int k = 0; k < i; k++){
                if(dp[k]==0 && freeS[k]==0) continue;

                // 把新 token i 加入 freeSet
                ll tmp = (freeS[k] + dp[k]*i) % m;

                // ———— 转移 1：跳过（a_i = 0）
                ndp[k]    = (ndp[k]    + dp[k]) % m;
                nfreeS[k] = (nfreeS[k] + tmp)   % m;

                // ———— 转移 2：匹配（a_i != 0）
                // 选一个 free token p，加权总和就是 tmp
                ndp[k+1]  = (ndp[k+1] + tmp) % m;
                // 用掉 p 后，freeSet 标签和 = tmpSet - p；对所有 p 求和：
                //   ∑(tmp - p) = tmp*(#free) - tmp
                ll cntFree = (ll)i - k;  // 这一刻 free 的 token 数
                ll addFS   = ( (tmp * cntFree) % m - tmp + m ) % m;
                nfreeS[k+1] = (nfreeS[k+1] + addFS) % m;
            }

            dp.swap(ndp);
            freeS.swap(nfreeS);
        }

        ll ans = 0;
        for(int k = 0; k <= n; k++){
            ans = (ans + dp[k]) % m;
        }
        cout << ans << "\n";
    }
    return 0;
}
