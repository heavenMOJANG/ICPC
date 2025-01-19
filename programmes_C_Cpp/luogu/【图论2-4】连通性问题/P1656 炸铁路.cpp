#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
struct Edge{ll u,v;}e[5010];
ll n,m,f[160];
ll findSet(ll x){return x==f[x]?x:f[x]=findSet(f[x]);}
void merge(ll x,ll y){
    ll fx=findSet(f[x]),fy=findSet(f[y]);
    if(fx!=fy) f[fx]=fy;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=m;++i){
        cin>>e[i].u>>e[i].v;
        if(e[i].u>e[i].v) swap(e[i].u,e[i].v);
    }
    sort(e+1,e+1+m,[](const Edge&x,const Edge&y){return x.u==y.u?x.v<y.v:x.u<y.u;});
    for(ll i=1;i<=m;++i){
        for(ll j=1;j<=n;++j) f[j]=j;
        for(ll j=1;j<=m;++j)
            if(j!=i) merge(e[j].u,e[j].v);
        for(ll j=2;j<=n;++j){
            if(f[findSet(j)]!=f[findSet(j-1)]){
                cout<<e[i].u<<" "<<e[i].v<<"\n";
                break;
            }
        }
    }
    return 0;
}
