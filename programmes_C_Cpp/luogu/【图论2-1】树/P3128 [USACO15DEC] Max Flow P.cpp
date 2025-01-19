#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
struct Edge{ll to,nxt;}e[200010];
ll n,m,t,head[100010],idx,f[100010][21],dep[100010],r[100010],maxn;
void addEdge(ll u,ll v){e[idx]={v,head[u]},head[u]=idx++;}
void dfs1(ll u,ll fa){
    f[u][0]=fa;
    dep[u]=dep[fa]+1;
    for(ll i=1;i<=t;++i) f[u][i]=f[f[u][i-1]][i-1];
    for(ll i=head[u];~i;i=e[i].nxt){
        ll v=e[i].to;
        if(v==fa) continue;
        dfs1(v,u);
    }
}
ll lca(ll u,ll v){
    if(dep[u]>dep[v]) swap(u,v);
    for(ll i=t;i>=0;--i)
        if(dep[f[v][i]]>=dep[u]) v=f[v][i];
    if(u==v) return u;
    for(ll i=t;i>=0;--i)
        if(f[u][i]!=f[v][i]) u=f[u][i],v=f[v][i];
    return f[u][0];
}
void dfs2(ll u,ll fa){
    for(ll i=head[u];~i;i=e[i].nxt){
        ll v=e[i].to;
        if(v==fa) continue;
        dfs2(v,u),r[u]+=r[v];
    }
    maxn=max(maxn,r[u]);
}
void solve(){
    memset(head,-1,sizeof(head));
    cin>>n>>m;
    t=(ll)log2(n)+1;
    for(ll i=1,u,v;i<n;++i) cin>>u>>v,addEdge(u,v),addEdge(v,u);
    dfs1(1,0);
    for(ll i=1;i<=m;++i){
        ll x,y;cin>>x>>y;
        ll fa=lca(x,y);
        r[x]++,r[y]++,r[fa]--,r[f[fa][0]]--;
    }
    dfs2(1,0);
    cout<<maxn<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}