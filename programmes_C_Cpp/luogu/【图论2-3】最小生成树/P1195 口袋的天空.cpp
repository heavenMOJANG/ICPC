#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll n,m,k,res,cnt,f[10010];
struct Edge{
    ll u,v,w;
    bool operator<(const Edge&t)const{return w<t.w;}
}edge[20010];
ll find_set(ll x){return f[x]==x?x:f[x]=find_set(f[x]);}
ll Kruskal(){
	sort(edge+1,edge+1+m);
	for(ll i=1;i<=m;++i){
		ll fx=find_set(edge[i].u),fy=find_set(edge[i].v);
		if(fx==fy) continue;
        f[fx]=fy;
		res+=edge[i].w;
		if(++cnt==n-k) return res;
	}
    return 0;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(ll i=1;i<=n;++i) f[i]=i;
	for(ll i=1;i<=m;++i) cin>>edge[i].u>>edge[i].v>>edge[i].w;
	Kruskal();
	if(k>n) cout<<"No Answer";
	else cout<<res;
    return 0;
}