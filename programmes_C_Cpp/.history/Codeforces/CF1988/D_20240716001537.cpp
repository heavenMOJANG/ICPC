#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,hp;cin>>n>>hp;
    vector<int>a(n+1),g[n+10],vis(n+1,0);
    vector<vector<int>>dp(n+1,vector<int>(2,0));
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1,u,v;i<n;++i){
        cin>>u>>v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    function<int(int)> dfs=[&](int u){
        vis[u]=1;
        dp[u][0]=0;
        dp[u][1]=a[u];
        for(auto v:g[u]){
            if(!vis[v]){
                dfs(v);
                dp[u][0]+=min(dp[v][0],dp[v][1]);
                dp[u][1]+=dp[v][0];
            }
        }
    };
    dfs(1);
    cout<<min(dp[1][0],dp[1][1])<<"\n";
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}