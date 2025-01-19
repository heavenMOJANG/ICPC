#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int M=60;
void solve(){
    int n;cin>>n;
    vector<int>a(n+1),g[n+1],pre(M+1),suf(M+1);
    vector<vector<int>>dp(n+1,vector<int>(61));
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1,u,v;i<n;++i){
        cin>>u>>v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    function<void(int,int)> dfs=[&](int u,int fa){
        for(int i=0;i<=M;++i) dp[u][i]=(i+1)*a[u];
        for(auto v:g[u]){
            if(v==fa) continue;
            dfs(v,u);
            for(int i=0;i<=M;++i) pre[i]=dp[v][i],suf[i]=dp[v][i];
            for(int i=1;i<=M;++i) pre[i]=min(pre[i],pre[i-1]);
            for(int i=M-1;i>=0;--i) suf[i]=min(suf[i],suf[i+1]);
            for(int i=0;i<=M;++i){
                int minn=LLONG_MAX;
                if(i-1>=0) minn=min(minn,pre[i-1]);
                if(i+1<=M) minn=min(minn,suf[i+1]);
                dp[u][i]+=minn;
            }
        }
    };
    dfs(1,-1);
    int ans=LLONG_MAX;
    for(int i=0;i<=M;++i) ans=min(ans,dp[1][i]);
    cout<<ans<<"\n";
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}