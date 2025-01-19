#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int>PII;
typedef pair<int,int>PLL;
const int inf=0x7fffffff;
struct Edge{int to,nxt,w;}edge[500010];
struct Node{
    int id,d;
    bool operator<(const Node&x) const{return d>x.d;}
};
int n,m,s,idx,head[100010],dis[100010],vis[100010];
void add(int u,int v,int w){edge[idx]={v,head[u],w};head[u]=idx++;}
void Dijkstra(int s){
    priority_queue<Node>q;
    dis[s]=0;
    q.push({s,dis[s]});
    while(!q.empty()){
		int u=q.top().id;q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];~i;i=edge[i].nxt){
			int v=edge[i].to;
			if(!vis[v]&&dis[v]>dis[u]+edge[i].w){
				dis[v]=dis[u]+edge[i].w;
				q.push({v,dis[v]});
			}
		}
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(head,-1,sizeof(head));
    memset(dis,inf,sizeof(dis));
    cin>>n>>m>>s;
    for(int i=1;i<=m;++i){int u,v,w;cin>>u>>v>>w,add(u,v,w);}
    Dijkstra(s);
    for(int i=1;i<=n;++i) cout<<(dis[i]<INT_MAX?dis[i]:INT_MAX)<<" ";
    return 0;
}