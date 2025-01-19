#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
constexpr ll mod=1e9+7;
ll n,q,k[100010],b[100010],p[100010];
void solve(){
    cin>>n>>q;
    vector<ll>g[n+10];
    for(ll i=1;i<=n;++i) cin>>k[i];
    for(ll i=1;i<=n;++i) cin>>b[i];
    for(ll i=1;i<=n;++i) cin>>p[i],g[i].push_back(p[i]);
    while(q--){
        ll x,l,y;cin>>x>>l>>y;
        while(l--){
            ll v=g[x][0];
            y=(y*k[v]%mod+b[v])%mod;
            x=g[x][0];
        }
        cout<<y<<"\n";
    }
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _;cin>>_;
    while(_--) solve();
    return 0;
}