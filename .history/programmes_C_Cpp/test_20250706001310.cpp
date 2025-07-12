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
        vector<ll> dp(n+1), nxt(n+1), sum(n+1), sumn(n+1), sq(n+1);
        dp[0] = 1;
        for(int i = 1; i <= n; i++){
            // 计算 1^2 + 2^2 + ... + i^2 mod m
            sq[i] = (sq[i-1] + 1LL*i*i) % m;
            fill(nxt.begin(), nxt.end(), 0);
            fill(sumn.begin(), sumn.end(), 0);
            for(int r = 0; r < i; r++){
                ll ways = dp[r];
                if(!ways) continue;
                // 新加入标签 i 后的 sumLabel
                ll s = (sum[r] + ways * i) % m;
                int r1 = r + 1;  // 跳过不取
                nxt[r1] = (nxt[r1] + ways) % m;
                sumn[r1] = (sumn[r1] + s) % m;
                // 取走一步
                int r2 = r;      
                nxt[r2] = (nxt[r2] + s) % m;
                ll t = (s * r1 % m - sq[i] + m) % m;
                sumn[r2] = (sumn[r2] + t) % m;
            }
            dp.swap(nxt);
            sum.swap(sumn);
        }
        ll ans = accumulate(dp.begin(), dp.end(), 0LL) % m;
        cout << ans << "\n";
    }
    return 0;
}
