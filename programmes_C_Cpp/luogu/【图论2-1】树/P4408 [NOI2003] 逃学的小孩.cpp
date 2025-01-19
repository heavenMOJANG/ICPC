#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
struct Edge{ll to,nxt,w;}e[1000010];
ll n,m,maxn,res,head[500010],idx,p,dis[500010],f[500010],s,t,fs[500010],ft[500010];
void addEdge(ll u,ll v,ll w){e[idx]={v,head[u],w},head[u]=idx++;}
void dfs(ll u,ll fa){
    if(maxn<dis[u]) maxn=dis[u],p=u;
	for(ll i=head[u];~i;i=e[i].nxt) {
		ll v=e[i].to;
        if(v==fa) continue;
		dis[v]=dis[u]+e[i].w;
		dfs(v,u);
	}
}
void dfs2(ll u,ll fa){
    for(ll i=head[u];~i;i=e[i].nxt){
		ll v=e[i].to;
        if(v==fa) continue;
		f[v]=f[u]+e[i].w;
		dfs2(v,u);
	}
}
void solve(){
    memset(head,-1,sizeof(head));
    cin>>n>>m;
    for(ll i=1,u,v,w;i<=m;++i) cin>>u>>v>>w,addEdge(u,v,w),addEdge(v,u,w);
    dfs(1,0);
    s=p;
    dis[s]=maxn=0;
    dfs(s,0);
    t=p;
    dfs2(s,0);
	for(ll i=1;i<=n;++i) fs[i]=f[i];
	f[t]=0;
	dfs2(t,0);
	for(ll i=1;i<=n;++i) ft[i]=f[i];
	for(ll i=1; i<=n; i++) if(i!=s&&i!=t) res=max(res,min(fs[i],ft[i]));
    cout<<maxn+res;
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}
