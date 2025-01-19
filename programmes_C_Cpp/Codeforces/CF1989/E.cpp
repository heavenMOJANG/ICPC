#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int mod=998244353;
void solve(){
    int n,k;cin>>n>>k;
    vector<vector<int>>dp(n+10,vector<int>(20)),s(n+10,vector<int>(20));
    dp[0][0]=s[0][0]=1;
    for(int i=1;i<=n;++i){
        if(i==2) dp[i][1]=1;
        if(i==n){
            for(int j=1;j<=k;++j) dp[i][j]=dp[i-2][j-1];
            (dp[i][k]+=dp[i-2][k])%=mod;
        }
        for(int j=1;j<=k;++j){
            (dp[i][j]+=dp[i-1][j-1])%=mod;
            if(i-3>=0)(dp[i][j]+=s[i-3][j-1])%=mod;
        }
        (dp[i][k]+=dp[i-1][k])%=mod;
        if(i-3>=0) (dp[i][k]+=s[i-3][k])%=mod;
        for(int j=0;j<=k;++j) (s[i][j]=s[i-1][j]+dp[i][j])%=mod;
    }
    cout<<dp[n][k]<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;//cin>>_;
    while(_--) solve();
    return 0;
}