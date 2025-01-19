#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int N=3e5+10;
constexpr int mod=998244353;
vector<int>e[N];
int n,dp[N][3]; 
void dfs(int now,int fa){
    for(auto it:e[now]){
        if(it==fa) continue;
        dfs(it,now);
        dp[now][0]=1;
        dp[now][1]=(dp[now][1]*(dp[it][0]+dp[it][1]))%mod;
        dp[now][2]=(dp[now][2]+dp[it][1]+dp[it][2])%mod;
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;++i) e[i].clear(),dp[i][0]=dp[i][1]=1,dp[i][2]=0;
    for(int i=1,u,v;i<n;++i){
        cin>>u>>v;
        e[u].push_back(v),e[v].push_back(u);
    }
    dfs(1,-1);
    cout<<(dp[1][0]+dp[1][1]+dp[1][2])%mod<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
