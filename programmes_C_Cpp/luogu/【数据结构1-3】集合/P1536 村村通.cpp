#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll n,m,f[1010];
ll find_set(ll x){return f[x]==x?x:f[x]=find_set(f[x]);}
void merge_set(ll x,ll y){
    ll fx=find_set(x),fy=find_set(y);
    if(fx!=fy){
        f[fx]=fy;
    }
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>n&&n){
        cin>>m;
        for(ll i=1;i<=n;++i) f[i]=i;
        for(ll i=1,u,v;i<=m;++i) cin>>u>>v,merge_set(u,v);
        ll res=0;
        for(ll i=1;i<=n;++i) if(f[i]==i) res++;
        cout<<res-1<<"\n";
    }
    return 0;
}