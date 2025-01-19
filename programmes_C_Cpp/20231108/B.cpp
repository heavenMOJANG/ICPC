#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,m;cin>>n>>m;
    vector<vector<char>>a(n+10,vector<char>(m+10,0));
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j) cin>>a[i][j];
    vector<vector<int>>dp(n+10,vector<int>(m+10,0));
    int ans=0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(a[i][j]=='1'){
                dp[i][j]=min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]})+1;
                ans+=dp[i][j];
            }
    cout<<ans<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
