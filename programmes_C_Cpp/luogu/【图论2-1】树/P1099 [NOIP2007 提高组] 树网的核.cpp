#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
struct Edge{ll to,nxt,w;}e[1000010];
ll n,s,p,head[500010],f[500010],vis[500010],dis[500010],minn=LLONG_MAX,idx;
void addEdge(ll u,ll v,ll w){e[idx]={v,head[u],w},head[u]=idx++;}
void dfs(ll u,ll fa){
    f[u]=fa;
    if(dis[u]>dis[p]) p=u;
	for(ll i=head[u];~i;i=e[i].nxt){
		ll v=e[i].to;
		if(v==fa||vis[v]) continue;
		dis[v]=dis[u]+e[i].w;
		dfs(v,u);
	}
}
void solve(){
    memset(head,-1,sizeof(head));
    cin>>n>>s;
    for(ll i=1,u,v,w;i<n;++i) cin>>u>>v>>w,addEdge(u,v,w),addEdge(v,u,w);
    dis[1]=1;
    dfs(1,0);
    dis[p]=0;
    dfs(p,0);
    ll top=p;
    for(ll i=top,j=top,l=1,r=0;i;i=f[i]){
		while(dis[j]-dis[i]>s) j=f[j];
        minn=min(minn,max(dis[top]-dis[j],dis[i]));
	}
	for(ll i=top;i;i=f[i]) vis[i]=1;
	for(ll i=top;i;i=f[i]){
		p=i;
		dis[p]=0;
		dfs(i,f[i]);
	}
	for(ll i=1;i<=n;++i) minn=max(minn,dis[i]);
    cout<<minn<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}
