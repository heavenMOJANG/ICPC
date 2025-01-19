#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
ll f[10010],dfn[10010],vis[10010],w[10010],ans[10010],frm[10010];
ll n,m,idx,cnt,maxn;
vector<ll>e[10010],g[10010];
map<ll,ll>mp;
stack<ll>s;
ll findSet(ll x){return f[x]==x?dfn[x]:f[x]=findSet(f[dfn[x]]);}
void tarjan(ll u){
    dfn[u]=f[u]=++idx;
    s.push(u);
    vis[u]=1;
    for(auto v:e[u]){
        if(!dfn[v]){
            tarjan(v);
            f[u]=min(f[v],f[u]);
        }
        else if(vis[v]) f[u]=min(f[v],f[u]);
    }
    ll tmp;
    if(dfn[u]==f[u]) {
        mp[f[u]]=++cnt;
        w[cnt]=0;
        do{
            tmp=s.top();s.pop();
            vis[tmp]=0;
            g[cnt].push_back(tmp);
            f[tmp]=f[u];
            w[cnt]+=frm[tmp];
        }while(u!=tmp);
    }
}
ll dfs(ll x){
    ll res=0;
    ans[x]=w[x];
    for(auto v:g[x])
        for(auto k:e[v]){
            ll b=mp[f[k]];
            if(ans[b]==-1) dfs(b);
            if(b!=x) res=max(res,ans[b]);
        }
    return ans[x]+=res;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;++i) cin>>frm[i];
    for(ll i=1,x,y;i<=m;++i){
        cin>>x>>y;
        if(x==y) m--,i--;
        else e[x].push_back(y);
    }
    for(ll i=1;i<=n;++i) if(!dfn[i]) tarjan(i);
    fill(ans+1,ans+1+cnt,-1);
    for(ll i=1;i<=cnt;++i){
        if(ans[i]==-1) dfs(i);
        maxn=max(maxn,ans[i]);
    }
    cout<<maxn;
    return 0;
}
