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
ll n,m,f[20010],a[20010];
ll cmp(Edge x,Edge y){return x.w>y.w;}
ll find_set(ll x){return f[x]==x?x:f[x]=find_set(f[x]);}
void merge_set(ll x,ll y){
    ll fx=find_set(x),fy=find_set(y);
    if(fx!=fy) f[fy]=fx;
    return;
}
ll check(ll x,ll y){return find_set(x)==find_set(y);}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
	for(ll i=1;i<=n;++i) f[i]=i;
	for(ll i=1;i<=m;++i) cin>>edge[i].u>>edge[i].v>>edge[i].w;
	sort(edge+1,edge+1+m,cmp);
	for(ll i=1;i<=m+1;++i){
		if(check(edge[i].u,edge[i].v)){cout<<edge[i].w;break;}
	    else{
	   		if(!a[edge[i].u]) a[edge[i].u]=edge[i].v;
	    	else merge_set(a[edge[i].u],edge[i].v);
	    	if(!a[edge[i].v]) a[edge[i].v]=edge[i].u;
	    	else merge_set(edge[i].u,a[edge[i].v]); 
		}
   }
    return 0;
}