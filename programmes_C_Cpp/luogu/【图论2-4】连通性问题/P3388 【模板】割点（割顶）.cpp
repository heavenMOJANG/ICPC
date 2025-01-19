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
const ll N=20010;
const ll M=100010;
ll dx[]={-1,1,0,0};
ll dy[]={0,0,-1,1};
struct Edge{ll to,nxt;}edge[M<<1];
ll n,m,head[N],dfn[N],low[N],cut[N],idx,dft,vis[N];
vector<ll>ans;
void add_edge(ll u,ll v){edge[idx]={v,head[u]},head[u]=idx++;}
void Tarjan(ll u,ll fa){
    low[u]=dfn[u]=++dft;
	ll tot=0;
	for(ll i=head[u];~i;i=edge[i].nxt){
		ll v=edge[i].to;
		if(!dfn[v]){
			++tot;
            Tarjan(v,fa);
			low[u]=min(low[u],low[v]);
			if((u==fa&&tot>=2)||(u!=fa&&dfn[u]<=low[v])) cut[u]=1;
		}
		else low[u]=min(low[u],dfn[v]);
    }
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(head,-1,sizeof(head));
    cin>>n>>m;
    for(ll i=1,u,v;i<=m;++i) cin>>u>>v,add_edge(u,v),add_edge(v,u);
    for(ll i=1;i<=n;++i) if(!dfn[i]) Tarjan(i,i);
    for(ll i=1;i<=n;++i) if(cut[i]) ans.push_back(i);
    cout<<ans.size()<<"\n";
    for(ll i=0;i<ans.size();++i) cout<<ans[i]<<" ";
    return 0;
}