#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
vector<ll>g[200010];
ll T,n,dp[200010][2],vis[200010],c[200010];
void dfs(ll u){
    dp[u][0]=0;
    dp[u][1]=c[u];
    for(auto v:g[u]){
        dfs(v);
        dp[u][0]+=dp[v][1];
        dp[u][1]+=min(dp[v][0],dp[v][1]);
    }
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        memset(dp,0,sizeof(dp));
        memset(c,0,sizeof(c));
        memset(vis,0,sizeof(vis));
        cin>>n;
        for(ll i=1;i<=n;++i) g[i].clear();
        for(ll i=1;i<=n;++i) cin>>c[i];
        for(ll i=1,x,y;i<n;++i){
            cin>>x>>y;
            vis[y]=1;
            g[x].push_back(y);
        }
        ll rt;
        for(ll i=1;i<=n;++i) if(!vis[i]){rt=i;break;}
        dfs(rt);
        cout<<min(dp[rt][0],dp[rt][1])<<"\n";
    }
    return 0;
}
