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
        // dp[j]: i 步后恰好做了 j 次匹配的方案权值和
        // freeSum[j]: 同样这些方案，当前所有可选 (free) token 标签总和，加权后累加
        vector<ll> dp(n+1, 0), freeSum(n+1, 0);
        vector<ll> ndp(n+1), nfree(n+1);

        dp[0] = 1;
        // 初始时 i=0, 空方案，freeSum[0]=0

        ll prefixSum = 0;  // 用来维护 1+2+...+i mod m
        for(int i = 1; i <= n; i++){
            prefixSum = (prefixSum + i) % m;
            fill(ndp.begin(),   ndp.end(),   0);
            fill(nfree.begin(), nfree.end(), 0);
            for(int j = 0; j <= i-1; j++){
                if(dp[j] == 0 && freeSum[j] == 0) continue;
                // 把 token i 加入 free 集合：
                // 新的 freeSum = old_freeSum + dp[j]*i
                ll fs = (freeSum[j] + dp[j]*i) % m;

                // —— 跳过 a_i = 0
                ndp[j]    = (ndp[j]    + dp[j]) % m;
                nfree[j]  = (nfree[j]  + fs)     % m;

                // —— 取 a_i != 0，从 free {…} 中选 p
                // 选 p 的标签和恰好 = fs
                ndp[j+1]  = (ndp[j+1] + fs)      % m;
                // 新的 freeSum 在移除 p 后 = fs - p，每个方案要累加 ∑(fs - p)
                // ∑ₚ (fs - p) = fs*(#free) - ∑ₚ p = fs*(cntFree) - fs
                ll cntFree = (ll)i - j;  // 此时 free token 数
                ll addF    = (fs * cntFree % m - fs + m) % m;
                nfree[j+1]= (nfree[j+1] + addF) % m;
            }
            swap(dp,   ndp);
            swap(freeSum, nfree);
        }

        ll ans = 0;
        for(int j = 0; j <= n; j++){
            ans = (ans + dp[j]) % m;
        }
        cout << ans << "\n";
    }
    return 0;
}
