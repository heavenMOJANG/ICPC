#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
typedef pair<ll,ll>PLL;
const ll inf=0x3f3f3f3f3f3f;
struct Edge{ll to,nxt,w;}edge[500010];
struct Node{
    ll id,d;
    bool operator<(const Node&x) const{return d>x.d;}
};
ll n,m,s,idx,head[100010],dis[100010],vis[100010];
void add(ll u,ll v,ll w){edge[idx]={v,head[u],w};head[u]=idx++;}
void Dijkstra(ll s){
    priority_queue<Node>q;
    dis[s]=0;
    q.push({s,dis[s]});
    while(!q.empty()){
		ll u=q.top().id;q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(ll i=head[u];~i;i=edge[i].nxt){
			ll v=edge[i].to;
			if(!vis[v]&&dis[v]>dis[u]+edge[i].w){
				dis[v]=dis[u]+edge[i].w;
				q.push({v,dis[v]});
			}
		}
    }
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(head,-1,sizeof(head));
    memset(dis,inf,sizeof(dis));
    cin>>n>>m>>s;
    for(ll i=1;i<=m;++i){ll u,v,w;cin>>u>>v>>w,add(u,v,w);}
    Dijkstra(s);
    for(ll i=1;i<=n;++i) cout<<dis[i]<<" ";
    return 0;
}