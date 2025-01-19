#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
typedef pair<ll,ll>PLL;
const ll inf=0x7f;
ll dx[]={-1,1,0,0};
ll dy[]={0,0,-1,1};
struct Edge{ll to,nxt,num;}edge[10010],edge_query[10010];
ll n,head[110],idx,dep[110],h[110],head_query[110],f[110],idx_query,vis[110],maxd,maxw,ans[110];
void add_edge(ll u,ll v){edge[idx]={v,head[u]},head[u]=idx++;}
void add_query(ll u,ll v,ll num){edge_query[idx_query]={v,head_query[u],num},head_query[u]=idx_query++;}
void dfs(ll u,ll f){
    for(ll i=head[u];~i;i=edge[i].nxt){
        ll v=edge[i].to;
        if(v==f) continue;
        dep[v]=dep[u]+1;
        dfs(v,u);
    }
}
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
    cin>>n;
    for(ll i=1;i<=n;++i) f[i]=i;
    for(ll i=1,u,v;i<n;++i) cin>>u>>v,add_edge(u,v),add_edge(v,u);
    dep[1]=1;
    dfs(1,-1);
    for(ll i=1;i<=n;++i) maxd=max(maxd,dep[i]),h[dep[i]]++;
    for(ll i=1;i<=n;++i) maxw=max(maxw,h[i]);
    ll x,y;cin>>x>>y;
    add_query(x,y,1),add_query(y,x,1);
    Tarjan(1);
    cout<<maxd<<"\n"<<maxw<<"\n"<<(dep[x]-dep[ans[1]])*2+dep[y]-dep[ans[1]];
    return 0;
}