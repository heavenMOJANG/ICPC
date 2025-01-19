#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,m,k,h[200010],ind[200010],d[200010],last;
vector<ll>g[200010];
void dfs(ll u){
    d[u]++;
    last=max(last,d[u]*k+h[u]);
    for(ll v:g[u]) if(d[v]<(d[u]+(h[u]>h[v]))) dfs(v);
}
void solve(){
    cin>>n>>m>>k;
    for(ll i=1;i<=n;++i) cin>>h[i],ind[i]=d[i]=0,g[i].clear();
    vector<pair<ll,ll>>vv;
    for(ll i=1,u,v;i<=m;++i) cin>>u>>v,g[u].push_back(v),ind[v]++;
    queue<ll>q;
    for(ll i=1;i<=n;++i) if(!ind[i]) q.push(i),vv.push_back({h[i],i});
    while(!q.empty()){
        ll u=q.front();q.pop();
        for(ll v:g[u]){
            d[v]=max(d[v],(d[u]+(h[u]>h[v])));
            ind[v]--;
            if(!ind[v]) q.push(v);
        }
    }
    last=0;
    for(ll i=1;i<=n;++i) last=max(last,d[i]*k+h[i]);
    sort(vv.begin(),vv.end());
    ll res=last;
    for(auto x:vv){
        res=min(res,last-x.first);
        dfs(x.second);
    }
    cout<<res<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
