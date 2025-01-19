#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
constexpr ll N=3000;
struct Edge{ll to,nxt;}e[4*N+10];
struct Node{
    ll u,v,w;
    bool operator<(const Node&x)const{return w<x.w;}
}b[2*N];
ll n,a[2*N+10],cost[2*N+10];
ll head[2*N],idx;
ll f[2*N+10],dp[2*N+10][N+10],siz[2*N],g[2*N],maxn=LLONG_MIN;
ll findSet(ll x){return f[x]==x?x:f[x]=findSet(f[x]);}
void addEdge(ll u,ll v){e[idx]={v,head[u]},head[u]=idx++;}
void dfs(ll u) {
    siz[u]=(u<=n);
    if(u<=n) {
        dp[u][a[u]]=0;
        dp[u][a[u]^1]=-cost[u];
    }
    for(ll i=head[u];~i;i=e[i].nxt){
        ll v=e[i].to;
        dfs(v);
        for(ll j=0;j<=siz[u]+siz[v];++j) g[j]=-1e9;
        for(ll j=0;j<=siz[u];++j)
            for(ll k=0;k<=siz[v];++k)
                g[j+k]=max(g[j+k],dp[u][j]+dp[v][k]+cost[u]*(j*(siz[v]-k)+k*(siz[u]-j)));
        siz[u]+=siz[v];
        for(ll j=0;j<=siz[u];++j) dp[u][j]=g[j];
    }
}
void exKruskal(){
    sort(b+1,b+n);
    for(ll i=1;i<n;++i){
        ll fx=findSet(b[i].u),fy=findSet(b[i].v);
        f[fx]=f[fy]=i+n;
        cost[i+n]=b[i].w;
        addEdge(i+n,fx);
        addEdge(i+n,fy);
    }
}
void solve(){
    memset(head,-1,sizeof(head));
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>a[i];
    for(ll i=1;i<=n;++i) cin>>cost[i];
    for(ll i=1;i<=2*n;++i) f[i]=i;
    for(ll i=1;i<n;++i) cin>>b[i].u>>b[i].v>>b[i].w;
    sort(b+1,b+n);
    exKruskal();
    dfs(2*n-1);
    for(ll i=0;i<=n;++i) maxn=max(maxn,dp[2*n-1][i]);
    cout<<maxn;
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}