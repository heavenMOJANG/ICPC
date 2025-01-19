#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
typedef pair<ll,ll>PLL;
const ll inf=0x7f;
const ll N=200010;
ll dx[]={-1,1,0,0};
ll dy[]={0,0,-1,1};
ll n,m,s,t,cnt,in[N],out[N],st[N],h[N];
vector<PLL>g[N];
stack<ll>stk;
void dfs(ll u){
    for(ll i=st[u];i<g[u].size();i=max(i+1,st[u])){
		ll v=g[u][i].first,w=g[u][i].second;
		if(h[w]) continue;
        h[w]=1;
        st[u]=i+1;
		dfs(v);
	}
    stk.push(u);
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1,u,v;i<=m;++i){
        cin>>u>>v;
        out[u]++,in[v]++;
        g[u].push_back({v,++cnt});
    }
    ll flag=0;
	for(ll i=1;i<=n;++i){
		ll p=in[i]-out[i];
		if(p) flag++;
		if(p==1) s=i;
		if(p==-1) t=i;
	}
	if(flag&&flag!=2){cout<<"No";return 0;}
	if(!flag) s=t=1;
	if(!s||!t){cout<<"No";return 0;}
	for(ll i=1;i<=n;++i) sort(g[i].begin(),g[i].end());
	dfs(t);
	while(!stk.empty()) cout<<stk.top()<<" ",stk.pop();
    return 0;
}