#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,m;cin>>n>>m;
    vector<vector<int>>g(n,vector<int>(m)),dp(n,vector<int>(m));
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j) cin>>g[i][j];
    dp[0][0]=g[0][0];
    for(int i=1;i<n;++i) dp[i][0]=__gcd(dp[i-1][0],g[i][0]);
    for(int j=1;j<m;++j) dp[0][j]=__gcd(dp[0][j-1],g[0][j]);
    for(int i=1;i<n;++i)
        for(int j=1;j<m;++j){
            int lGcd=__gcd(dp[i][j-1],g[i][j]);
            int tGcd=__gcd(dp[i-1][j],g[i][j]);
            dp[i][j]=max(lGcd,tGcd);
        }
    cout<<dp[n-1][m-1]<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}