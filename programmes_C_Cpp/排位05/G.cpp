#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    vector<int>ans(40,0);
    vector<vector<int>>dp(40,vector<int>(40,0));
    ans[1]=1;
    int n=30;
    for(int i=0;i<=n;++i) dp[i][0]=1;
    for(int i=1;i<=n;++i) dp[i][1]=1,dp[0][i]=0;
    function<int(int,int)>cal=[&](int n,int m){
        int res=1;
        for(int i=1;i<=m;++i) res=res*(n-m+i)/i;
        return res;
    };
    for(int i=1;i<=n;++i){
        for(int j=2;j<=n;++j){
            dp[i][j]=0;
            for(int k=0;k*i<=j;++k) dp[i][j]+=cal(ans[i]+k-1,k)*dp[i-1][j-k*i];
        }
        ans[i+1]=dp[i][i+1];
    }
    while(cin>>n&&n) cout<<(n==1?1ll:ans[n]*2)<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
