#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x7fffffff;
const ll N=100010;
ll n,m,w[N],maxn[N],minn[N],in[N],dp[N],dfn[N],low[N],fa[N],instack[N],vis[N],idx,cnt;
vector<ll>G[100010],g[100010];
stack<ll>s;
queue<ll>q;
void tarjan(ll u){
	low[u]=dfn[u]=++idx;
	instack[u]=1;
	s.push(u);
	for(auto v:G[u])
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(instack[v]) low[u]=min(low[u],dfn[v]);
	if(dfn[u]==low[u]){
		cnt+=1;
		ll Top=-1;
		while(!s.empty()&&Top!=u){
			Top=s.top();
			fa[Top]=cnt;
			instack[Top]=0;
			s.pop();
		}
	}
}
void topoSort(){
	vis[fa[1]]=1;
	for(ll i=1;i<=cnt;++i) if(!in[i]) q.push(i);
	while(!q.empty()){
		ll u=q.front();q.pop();
		for(auto v:g[u]) {
			if(vis[u]){
				vis[v]=1;
				minn[v]=min(minn[v],minn[u]);
				dp[v]=max(dp[u],max(dp[v], maxn[v]-minn[v]));
			}
			if(!(--in[v])) q.push(v);
		}
	}
	cout<<dp[fa[n]];
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;++i) cin>>w[i];
    for(ll i=1,x,y,z;i<=m;++i){
        cin>>x>>y>>z;
        G[x].push_back(y);
        if(z==2) G[y].push_back(x);
    }
    for(ll i=1;i<=n;++i) if(!dfn[i]) tarjan(i);
	for(ll i=1;i<=n;++i) minn[i]=inf;
	for(ll i=1;i<=n;++i){
		maxn[fa[i]]=max(maxn[fa[i]],w[i]);
		minn[fa[i]]=min(minn[fa[i]],w[i]);
	}
	for(ll i=1;i<=n;++i)
		for(auto v:G[i])
			if(fa[i]!=fa[v]){
				g[fa[i]].push_back(fa[v]);
				in[fa[v]]++;
			}
	topoSort();
    return 0;
}