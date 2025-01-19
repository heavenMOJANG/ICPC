#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll n,m,res,vis[100010],f[100010];
struct Edge{
    ll u,v,w;
    bool operator>(const Edge&t)const{return w>t.w;}
}edge[100010];
ll find_set(ll x){return f[x]==x?x:f[x]=find_set(f[x]);}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;++i) f[i]=i;
    for(ll i=1,x;i<=m;++i) cin>>x,vis[x]=1;
    for(ll i=1;i<n;++i) cin>>edge[i].u>>edge[i].v>>edge[i].w,res+=edge[i].w;
    sort(edge+1,edge+n,greater<Edge>());
    for(ll i=1;i<n;++i){
        ll fx=find_set(edge[i].u),fy=find_set(edge[i].v);
        if(!(vis[fx]&&vis[fy])){
            f[fy]=fx;
            vis[fx]=(vis[fx]||vis[fy]);
            res-=edge[i].w;
        }
    }
    cout<<res;
    return 0;
}