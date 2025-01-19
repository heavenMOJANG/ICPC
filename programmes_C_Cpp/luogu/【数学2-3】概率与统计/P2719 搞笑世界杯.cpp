#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    n>>=1;
    vector<vector<double>>dp(n+1,vector<double>(n+1,0.0));
    for(int i=2;i<=n;++i) dp[0][i]=dp[i][0]=1;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j) dp[i][j]=(dp[i][j-1]+dp[i-1][j])*0.5;
    cout<<fixed<<setprecision(4)<<dp[n][n]<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
