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

        // dp[k]    = 当前已做 k 次匹配的所有方案，权值之和 (＝∑ ∏ p)
        // freeS[k] = 这些方案对应的「所有尚未被用掉的 token 标签之和」(加权后)
        vector<ll> dp(n+1, 0), freeS(n+1, 0);
        vector<ll> ndp(n+1), nfreeS(n+1);

        dp[0] = 1;      // 0 步时，空方案，权值 1
        freeS[0] = 0;   // 没有 token 被用掉，freeSet = {}，标签和 0

        ll totSum = 0;  // 维护 1+2+...+i mod m
        for(int i = 1; i <= n; i++){
            totSum = (totSum + i) % m;

            // 清零下一行
            fill(ndp.begin(),   ndp.end(),   0);
            fill(nfreeS.begin(),nfreeS.end(),0);

            for(int k = 0; k < i; k++){
                if(dp[k] == 0 && freeS[k] == 0) continue;

                // 先把新的 token i 加入到所有「free 集合」里：
                // 对于每个「旧方案」，freeSet 标签之和要 + i
                ll tmpSum = (freeS[k] + dp[k] * i) % m;

                // —— 转移 1：跳过（a_i = 0）
                // 匹配数 k 不变，权值 dp[k] 也不变
                ndp[k]      = (ndp[k]      + dp[k]) % m;
                // freeSet 标签之和累加 tmpSum
                nfreeS[k]   = (nfreeS[k]   + tmpSum) % m;

                // —— 转移 2：匹配（a_i != 0）
                // 选择一个 free token p，从而权值要乘以 p，并把它移出 freeSet
                // 对所有方案而言，∑₍p∈free₎ p = tmpSum
                // 所以新方案数（加权）应加 tmpSum
                ndp[k+1]    = (ndp[k+1]    + tmpSum) % m;
                // 而移出 p 之后，freeSet 的标签之和 = tmpSum - p
                // ∑₍p∈free₎ (tmpSum - p) = tmpSum*(#free) - tmpSum
                // 其中 #free = i - k
                ll cntFree = ( (ll)i - k + m ) % m;
                ll addFreeS = ( (tmpSum * cntFree) % m - tmpSum + m ) % m;
                nfreeS[k+1] = (nfreeS[k+1] + addFreeS) % m;
            }

            // 滚动
            dp.swap(ndp);
            freeS.swap(nfreeS);
        }

        // 答案是所有 k=0..n 的 dp[k] 之和
        ll ans = 0;
        for(int k = 0; k <= n; k++){
            ans = (ans + dp[k]) % m;
        }
        cout << ans << "\n";
    }
    return 0;
}
