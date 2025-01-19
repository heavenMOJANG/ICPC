#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge{ll to,nxt;}edge[1000010];
ll f[500010][20],head[500010],dep[500010],idx;
ll n,m,root;
void add_edge(ll u,ll v){edge[idx]={v,head[u]},head[u]=idx++;}
void dfs(ll x,ll u){
    dep[x]=dep[u]+1;
    f[x][0]=u;
    for(ll i=1;(1<<i)<=dep[x];++i) f[x][i]=f[f[x][i-1]][i-1];
    for(ll i=head[x];~i;i=edge[i].nxt) if(edge[i].to!=u) dfs(edge[i].to,x);
}
ll LCA(ll u,ll v){
    if(dep[u]<dep[v]) swap(u,v);
    for(ll i=19;i>=0;--i) if(dep[u]-(1<<i)>=dep[v]) u=f[u][i];
    if(u==v) return u;
    for(ll i=19;i>=0;--i) if(f[u][i]!=f[v][i]) u=f[u][i],v=f[v][i];
    return f[u][0];
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(head,-1,sizeof(head));
    cin>>n>>m>>root;
    for(ll i=1,u,v;i<n;++i){
        cin>>u>>v;
        add_edge(u,v),add_edge(v,u);
    }
    dfs(root,0);
    while(m--){
        ll a,b;cin>>a>>b;
        cout<<LCA(a,b)<<"\n";
    }
    return 0;
}