#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
struct Edge{ll to,nxt,w;}e[200010];
struct Node{
    ll id,d;
    bool operator<(const Node&x)const{return d>x.d;}
};
ll _,n,m,head[5010],shortestDistance[5010],secondShortestDistance[5010],idx;
void addEdge(ll u,ll v,ll w){e[idx]={v,head[u],w},head[u]=idx++;}
void dijkstra(){
    for(ll i=1;i<=n;++i) shortestDistance[i]=secondShortestDistance[i]=inf;
    priority_queue<Node>pq;
    pq.push({1,shortestDistance[1]=0});
    while(!pq.empty()){
		ll u=pq.top().id,d=pq.top().d;pq.pop();
        if(d>secondShortestDistance[u]) continue;
		for(ll i=head[u];~i;i=e[i].nxt){
			ll v=e[i].to,w=e[i].w,dis=d+w;
			if(dis<shortestDistance[v]){
				swap(shortestDistance[v],dis);
				pq.push({v,shortestDistance[v]});
			}
			if(dis<secondShortestDistance[v]&&shortestDistance[v]<dis){
				secondShortestDistance[v]=dis;
				pq.push({v,secondShortestDistance[v]});
			}
		}
	}
}
void solve(){
    memset(head,-1,sizeof(head));
    cin>>n>>m;
    for(ll i=1,u,v,w;i<=m;++i) cin>>u>>v>>w,addEdge(u,v,w),addEdge(v,u,w);
    dijkstra();
    cout<<secondShortestDistance[n];
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    _=1;
    while(_--) solve();
    return 0;
}