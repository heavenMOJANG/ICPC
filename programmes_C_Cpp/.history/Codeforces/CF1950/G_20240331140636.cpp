#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<vector<string>>s(n,vector<string>(2));
    for(int i=0;i<n;++i) cin>>s[i][0]>>s[i][1];
    vector<vector<int>>g(20,vector<int>(20,0));
    for(int i=0;i<n;++i)
        for(int j=i+1;j<n;++j)
            if(s[i][0]==s[j][0]||s[i][1]==s[j][1]) g[i][j]=g[j][i]=1; 
    vector<vector<int>>dp(1<<20,vector<int>(20));
    for(int i=0;i<n;++i) dp[1<<i][i]=1;
    int ans=0;
    for(int i=1;i<(1<<n);++i)
        for(int j=0;j<n;++j)
            if(dp[i][j]){
                int sum=0,x=i;
                while(x){
                    if(x%2) sum++;
                    x/=2;
                }
                ans=max(ans,sum);
                for(int k=0;k<n;++k) if(((i>>k)&1)==0&&g[j][k]==1) dp[i|1<<k][k]=1;
            }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
