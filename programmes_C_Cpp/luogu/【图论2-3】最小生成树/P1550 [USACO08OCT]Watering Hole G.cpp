#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
struct Edge{ll u,v,w;}edge[100010];
ll n,m,f[310];
void add_edge(ll u,ll v,ll w){edge[++m]={u,v,w};}
ll cmp(Edge x,Edge y){return x.w<y.w;}
ll find_set(ll x){return f[x]==x?f[x]:f[x]=find_set(f[x]);}
ll kruskal(){
    ll res=0,cnt=0;
    sort(edge+1,edge+1+m,cmp);
    for(ll i=1;i<=n;++i) f[i]=i;
    for(ll i=1;i<=m;++i){
        if(cnt==n-1) break;
        ll fu=find_set(edge[i].u),fv=find_set(edge[i].v);
        if(fu==fv) continue;
        else{
            res+=edge[i].w;
            f[fu]=fv;
            cnt++;
        }
    }
    return res;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1,w;i<=n;++i) cin>>w,add_edge(i,n+1,w);
    for(ll i=1;i<=n;++i)
        for(ll j=1;j<=n;++j){
            ll w;cin>>w;add_edge(i,j,w);
        }
    n++;
    cout<<kruskal();
    return 0;
}