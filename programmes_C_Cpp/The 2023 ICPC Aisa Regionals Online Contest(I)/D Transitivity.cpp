#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,m,f[1000010],b[1000010];
ll findSet(ll x){return x==f[x]?x:f[x]=findSet(x);}
void merge(ll x,ll y){
    ll fx=findSet(x),fy=findSet(y);
    if(fx!=fy) f[fy]=fx;
    return;
}
void solve(){
    cin>>n>>m;
    for(ll i=1;i<=n;++i) f[i]=i;
    for(ll i=1,u,v;i<=m;++i){
        cin>>u>>v;
        merge(u,v);
    }
    for(ll i=1;i<=n;++i) b[findSet()]
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}
