#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
struct Edge{ll to,nxt,w;}edge[2100010];
struct Node{
    ll id,d;
    bool operator<(const Node&x)const{return d>x.d;}
};
ll n,m,k,s,t,head[2100010],dis[2100010],vis[2100010],idx;
void addEdge(ll u,ll v,ll w){edge[idx]={v,head[u],w},head[u]=idx++;}
void dijkstra(ll s){
    fill(dis,dis+n*(k+1)+1,inf);
    priority_queue<Node>q;
    q.push({s,dis[s]=0});
    while(!q.empty()){
        ll u=q.top().id;q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(ll i=head[u];~i;i=edge[i].nxt){
            ll v=edge[i].to;
            if(dis[v]>dis[u]+edge[i].w){
                dis[v]=dis[u]+edge[i].w;
                q.push({v,dis[v]});
            }
        }
    }
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(head,-1,sizeof(head));
    cin>>n>>m>>k>>s>>t;
    for(ll i=1,u,v,w;i<=m;++i){
        cin>>u>>v>>w;
        addEdge(u,v,w);
        addEdge(v,u,w);
        for(ll j=1;j<=k;++j){
			addEdge(j*n+u,j*n+v,w);
			addEdge(j*n+v,j*n+u,w);
			addEdge((j-1)*n+u,j*n+v,0);
			addEdge((j-1)*n+v,j*n+u,0);
		}
    }
    for(ll i=0;i<k;++i) addEdge(i*n+t,(i+1)*n+t,0);
    dijkstra(s);
    cout<<dis[n*k+t];
    return 0;
}
