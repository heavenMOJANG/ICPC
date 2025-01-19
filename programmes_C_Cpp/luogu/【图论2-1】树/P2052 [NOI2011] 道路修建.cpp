#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
struct Edge{ll to,nxt,w;}e[2000010];
ll n,head[1000010],idx,siz[1000010],sum;
void addEdge(ll u,ll v,ll w){e[idx]={v,head[u],w},head[u]=idx++;}
void dfs(ll u,ll f){
    siz[u]=1;
    for(ll i=head[u];~i;i=e[i].nxt){
        ll v=e[i].to;
        if(v==f) continue;
        dfs(v,u);
        sum+=(abs(n-2*siz[v]))*e[i].w;
        siz[u]+=siz[v];
    }
}
void solve(){
    memset(head,-1,sizeof(head));
    cin>>n;
    for(ll i=1,u,v,w;i<n;++i){
        cin>>u>>v>>w;
        addEdge(u,v,w);
        addEdge(v,u,w);
    }
    dfs(1,-1);
    cout<<sum<<"\n";
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}