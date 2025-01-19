#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x7fffffff;
struct Edge{ll to,nxt,w;}E[100010];
struct edge{
    ll u,v,w;
    bool operator<(const edge&x)const{return w>x.w;}
}e[100010];
ll n,m,q,idx,vis[50010],f[50010],fa[50010],dis[50010],dep[50010],head[50010];
void dfs(ll u,ll pre){
    vis[u]=1;
    fa[u]=pre;
    dep[u]=dep[pre]+1;
    for(ll i=head[u];~i;i=E[i].nxt){
        ll v=E[i].to;
        if(vis[v]) continue;
        dis[v]=E[i].w;
        dfs(v,u);
    }
}
ll solve(ll u,ll v){
    ll res1=inf,res2=inf;
    if(dep[u]<dep[v]) swap(u,v);
    for(;dep[u]>dep[v];u=fa[u]) res1=min(res1,dis[u]);
    if(u==v) return res1;
    for(;u!=v;u=fa[u],v=fa[v]) res1=min(res1,dis[u]),res2=min(res2,dis[v]);
    return min(res1,res2);
}
ll findSet(ll x){return f[x]==x?x:f[x]=findSet(f[x]);}
void kruskal(){
    for(ll i=1;i<=n;++i) f[i]=i;
    sort(e+1,e+1+m);
    ll cnt=0;
    for(ll i=1;i<=m;++i){
        ll fx=findSet(e[i].u),fy=findSet(e[i].v);
        if(fx==fy) continue;
        f[fy]=fx;
        E[++idx]={e[i].v,head[e[i].u],e[i].w},head[e[i].u]=idx;
        E[++idx]={e[i].u,head[e[i].v],e[i].w},head[e[i].v]=idx;
        if(++cnt==n-1) break;
    }
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(head,-1,sizeof(head));
    cin>>n>>m;
    for(ll i=1,u,v,w;i<=m;++i) cin>>u>>v>>w,e[i]={u,v,w};
    kruskal();
    for(ll i=1;i<=n;++i) if(!vis[i]) dfs(i,0);
    cin>>q;
    while(q--){
        ll u,v;cin>>u>>v;
        if(findSet(u)!=findSet(v)) cout<<"-1\n";
        else cout<<solve(u,v)<<"\n";
    }
    return 0;
}
