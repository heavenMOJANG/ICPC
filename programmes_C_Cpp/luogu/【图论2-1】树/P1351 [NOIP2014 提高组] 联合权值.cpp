#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
constexpr ll mod=10007;
ll n,w[200010],vis[200010],idx,maxn,sum;
vector<ll>g[200010];
void dfs(ll u){
    vis[u]=1;
    ll maxw=0,secMaxw=0,pre=0;
    for(ll v:g[u]){
        if(vis[v]) continue;
        if(w[v]>maxw) secMaxw=maxw,maxw=w[v];
        else if(w[v]>secMaxw) secMaxw=w[v];
        sum=(sum+w[v]*pre%mod)%mod;
        pre=(pre+w[v])%mod;
        for(ll x:g[v]){
            if(vis[x]) continue;
            sum=(sum+w[u]*w[x]%mod)%mod;
            maxn=max(maxn,w[u]*w[x]);
        }
    }
    maxn=max(maxn,maxw*secMaxw);
    for(ll v:g[u]) if(!vis[v]) dfs(v);
    return;
}
void solve(){
    cin>>n;
    for(ll i=1,u,v;i<n;++i) cin>>u>>v,g[u].push_back(v),g[v].push_back(u);
    for(ll i=1;i<=n;++i) cin>>w[i];
    dfs(1);
    cout<<maxn<<" "<<sum*2%mod<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}