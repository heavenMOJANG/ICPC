#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
vector<ll>g[10010];
stack<ll>s;
ll n,m,stp,cnt,dfn[10010],low[10010],vis[10010],q[10010],b[10010],sum;
void tarjan(ll u){
	dfn[u]=low[u]=++stp;
	s.push(u);
	vis[u]=1;
	for(auto v:g[u]){
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
        else if(vis[v]) low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u]){
		cnt++; 
		ll v;
		do{
			q[cnt]++;
			v=s.top();
			b[v]=cnt;
			vis[v]=0;
			s.pop();
		}while(v!=u);
	}
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
	while(m--){
		ll x,y;cin>>x>>y;
		g[x].push_back(y);
	}
	for(ll i=1;i<=n;++i) if(!dfn[i]) tarjan(i);
	for(ll i=1;i<=cnt;++i) if(q[i]>1) sum++;
	cout<<sum;
    return 0;
}
