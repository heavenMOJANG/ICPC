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
const ll N=500010;
const ll M=2000010;
ll dx[]={-1,1,0,0};
ll dy[]={0,0,-1,1};
struct Edge{ll to,nxt;}edge[M*2];
ll n,m,head[N],dfn[N],low[N],idx,is_bridge[N],num,cnt;
vector<ll>dcc[N];
stack<ll>s;
void add_edge(ll u,ll v){edge[idx]={v,head[u]},head[u]=idx++;}
void tarjan(ll u,ll from){
    dfn[u]=low[u]=++num;
	s.push(u);
	for(ll i=head[u];~i;i=edge[i].nxt){
		ll v=edge[i].to;
		if(!dfn[v]){
			tarjan(v,i);
			low[u]=min(low[u],low[v]);
			if(dfn[u]<low[v])
			is_bridge[i]=is_bridge[i^1]=1;
		}
		else if (i!=(from^1)) low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u]){
		cnt++;
		ll v;
		do{
			v=s.top();s.pop();    
			dcc[cnt].push_back(v);
		}while(v!=u);
	}
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(head,-1,sizeof(head));
    cin>>n>>m;
    for(ll i=1,u,v;i<=m;++i) cin>>u>>v,add_edge(u,v),add_edge(v,u);
    for(ll i=1;i<=n;++i) if(!dfn[i]) tarjan(i,-1);
    cout<<cnt<<"\n";
    for(ll i=1;i<=cnt;++i){
    	cout<<dcc[i].size();
    	for(ll j=0;j<dcc[i].size();++j) cout<<" "<<dcc[i][j];
    	cout<<"\n";
    }
    return 0;
}