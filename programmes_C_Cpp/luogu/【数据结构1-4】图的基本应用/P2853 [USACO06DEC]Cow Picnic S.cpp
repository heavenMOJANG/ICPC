#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll k,n,m,p[110],h[1010],vis[1010],res;
vector<ll>g[1010];
void dfs(ll u){
	h[u]++;
	vis[u]=1;
	for(ll i=0;i<g[u].size();++i){
        ll v=g[u][i];
		if(!vis[v]) dfs(v);
    }
	return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>k>>n>>m;
    for(ll i=1;i<=k;++i) cin>>p[i];
	for(ll i=1,u,v;i<=m;++i) cin>>u>>v,g[u].push_back(v);
	for(ll i=1;i<=k;++i){  //遍历所有牛能到达的地方
		memset(vis,0,sizeof(vis));  //记得清空一下
		dfs(p[i]);
	}
	for(ll i=1;i<=n;++i) if(h[i]==k) res++;
	cout<<res;
    return 0;
}