#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<pair<string,string>>s(n);
    for(int i=0;i<n;++i) cin>>s[i].first>>s[i].second;
    vector<vector<int>>g(20,vector<int>(20,0));
    for(int i=0;i<n;++i)
        for(int j=i+1;j<n;++j)
            if(s[i].first==s[j].first||s[i].second==s[j].second) g[i][j]=g[j][i]=1; 
    vector<vector<int>>dp(1<<20,vector<int>(20));
    dp[1][0]=0;
    for(int i=1;i<(1<<n);++i)
        for(int j=0;j<n;++j)
            if((i>>j)&1)
                for(int k=0;k<n;++k)
                    if((i^(1<<j))>>k&1) dp[i][j]=min(dp[i][j],dp[i^(1<<j)][k]+g[k][j]);
    cout<<n-dp[(1<<n)-1][n-1]<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
