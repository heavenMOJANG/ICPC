#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
vector<int> cal(string s){
    int n=s.size();
    vector<vector<int>>vis(n,vector<int>(n,0));
    vector<int>dp(n,INT_MAX);
    for(int i=0;i<n;++i) vis[i][i]=1;
    for(int i=2;i<=n;++i)
        for(int l=0;l<n;++l){
            int r=l+i-1;
            if(r>=n) break;
            if(i==2) vis[l][r]=(s[l]==s[r]);
            else vis[l][r]=(s[l]==s[r])&&vis[l+1][r-1];
        }
    for(int i=0;i<n;++i)
        if(vis[0][i]) dp[i]=0;
        else
            for(int j=0;j<i;++j) if(vis[j+1][i]&&dp[i]>dp[j]+1) dp[i]=dp[j]+1;
    return dp;
}
void solve(){
    string s;cin>>s;
    vector<int>res=cal(s);
    cout<<res.back()+1<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
