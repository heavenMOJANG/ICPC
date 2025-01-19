#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,m;cin>>n>>m;
    vector<pii>g[n+1];
    vector<int>dfn(n+1),low(n+1),siz(n+1),vis(n+1);
    stack<int>s;
    int minn=LLONG_MAX,idx=0,cnt=0;
    for(int i=1,u,v;i<=m;++i){
        cin>>u>>v;
        g[u].push_back({v,i});
        g[v].push_back({u,i});
    }
    function<void(int,int)> tarjan=[&](int u,int id){
        dfn[u]=low[u]=++idx;
        s.push(u);
        for(auto [v,id2]:g[u]){
            if(!dfn[v]){
                tarjan(v,id2);
                low[u]=min(low[u],low[v]);
            }
            else if(id!=id2) low[u]=min(low[u],low[v]);
        }
        if(dfn[u]==low[u]){
            cnt++;
            while(1){
                int v=s.top();s.pop();
                if(u==v) break;
            }
            minn=min(minn,siz[u]*(siz[u]-1)/2+(n-siz[u])*(n-siz[u]-1)/2);
        }
    };
    function<void(int,int)> dfs=[&](int u,int fa){
        siz[u]=1;vis[u]=1;
        for(auto [v,id]:g[u]){
            if(u==v||vis[v]) continue;
            dfs(v,u);
            siz[u]+=siz[v];
        }
    };
    dfs(1,-1);
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}