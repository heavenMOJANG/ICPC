#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
struct Edge{ll from,to,w;}edge[250010];
ll n,m,g[510][510],f[510],idx,res;
ll cmp(Edge x,Edge y){return x.w<y.w;}
ll find_set(ll x){return f[x]==x?x:f[x]=find_set(f[x]);}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>m>>n;
    for(ll i=1;i<=n;++i)
        for(ll j=1;j<=n;++j) cin>>g[i][j];
    int cnt=0;
    for(ll i=1;i<=n;++i)
        for(ll j=1;j<=n;++j)
            if(g[i][j]) edge[++idx]={i,j,min(g[i][j],m)};
            else edge[++idx]={i,j,m};
    sort(edge+1,edge+1+idx,cmp);
    for(ll i=1;i<=n;++i) f[i]=i;
    res=m;
	for(ll i=1;i<=idx;++i){
        ll fx=find_set(edge[i].from),fy=find_set(edge[i].to);
		if(fx!=fy){
            f[fx]=fy;
            res+=edge[i].w;
        }
	}
	cout<<res<<"\n";
    return 0;
}