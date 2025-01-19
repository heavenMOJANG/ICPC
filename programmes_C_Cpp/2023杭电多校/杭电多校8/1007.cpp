#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,m,k,f[100010],q[100010];
ll __find(ll x){return f[x]==x?x:f[x]=__find(f[x]);}
void __merge(ll x,ll y){
    ll fx=__find(x),fy=__find(y);
    if(fx!=fy) f[fx]=fy;
    return;
}
void solve(){
    cin>>n>>m;
    for(ll i=1;i<=n;++i) f[i]=i;
    for(ll i=1,u,v;i<=m;++i){
        cin>>u>>v;
        __merge(u,v);
    }
    cin>>k;
    for(ll i=1;i<=k;++i) cin>>q[i];
    for(ll i=2;i<=k;++i) if(__find(q[1])!=__find(q[i])){cout<<"NO\n";return;}
    cout<<"YES\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}