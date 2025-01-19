#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
const int N = 10010, M = 20010;
ll n,m,s,t,f[10010];
struct Edge{
	ll x,y,w;
	bool operator<(const Edge&t) const{return w<t.w;}
}edge[20010];
int find_set(ll x){return f[x]==x?x:f[x]=find_set(f[x]);}
ll kruskal(ll n){
	sort(edge+1,edge+1+m);
	for(ll i=1;i<=m;++i){
		ll fx=find_set(edge[i].x),fy=find_set(edge[i].y);
		if(fx!=fy){
			f[fx]=fy;
			if(find_set(s)==find_set(t)) return edge[i].w;
		}
	}
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>s>>t;
	for(ll i=1;i<=n;++i) f[i]=i;
	for(ll i=1;i<=m;++i) cin>>edge[i].x>>edge[i].y>>edge[i].w;
	cout<<kruskal(n);
    return 0;
}