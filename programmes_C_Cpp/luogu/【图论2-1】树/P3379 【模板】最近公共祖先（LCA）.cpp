#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge{ll to,nxt,num;}edge[1000010],edge_query[1000010];
ll f[500010],head[500010],head_query[500010],ans[500010],idx,idx_query,vis[500010];
ll n,m,root;
void add(ll u,ll v){edge[idx]={v,head[u]},head[u]=idx++;}
void add_query(ll u,ll v,ll num){edge_query[idx_query]={v,head_query[u],num},head_query[u]=idx_query++;}
ll find_set(ll x){return f[x]==x?x:f[x]=find_set(f[x]);}
void Tarjan(ll u){
    vis[u]=1;
    for(ll i=head[u];~i;i=edge[i].nxt){
        ll v=edge[i].to;
        if(!vis[v]){Tarjan(v);f[v]=u;}
    }
    for(ll i=head_query[u];~i;i=edge_query[i].nxt){
        ll v=edge_query[i].to;
        if(vis[v]) ans[edge_query[i].num]=find_set(v);
    }
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(head,-1,sizeof(head));
    memset(head_query,-1,sizeof(head_query));
    cin>>n>>m>>root;
    for(ll i=1;i<n;++i){
        f[i]=i;
        ll u,v; cin>>u>>v;
        add(u,v),add(v,u);
    }
    f[n]=n;
    for(ll i=1;i<=m;++i){
        ll a,b; cin>>a>>b;
        add_query(a,b,i),add_query(b,a,i);
    }
    Tarjan(root);
    for(ll i=1;i<=m;++i) cout<<ans[i]<<"\n";
    return 0;
}