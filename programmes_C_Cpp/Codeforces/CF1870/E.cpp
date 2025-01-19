#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;++i) cin>>a[i];
    vector<vector<int>>dp(n+1,vector<int>(n+1));
    vector<vector<int>>vis(n+1,vector<int>(n+1));
    dp[0][0]=1;
    int ans=0;
    for(int i=1;i<=n;++i){
        dp[i]=dp[i-1];
        vector<int>v(n+2);
        int mex=0;
        for(int j=i;j>=1;--j){
            v[a[j]]=1;
            if(v[mex]){
                while(v[mex]) mex++;
                if(vis[j][mex]) continue;
                vis[j][mex]=1;
                for(int k=0;k<=j;++k) if(dp[j-1][k]) dp[i][k^mex]=1;
            }
        }
        for(int j=1;j<=n;++j) if(dp[i][j]) ans=max(ans,j);
    }
    cout<<ans<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
