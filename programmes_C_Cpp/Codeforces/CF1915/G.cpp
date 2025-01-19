#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
struct Node{
    int id,d,s;
    bool operator>(const Node&b)const{return d>b.d;}
};
int n,m,cost[1010],dis[1010][1010],vis[1010][1010];
vector<Node>g[1010];
void dijkstra(int s){
    priority_queue<Node,vector<Node>,greater<Node>>q;
    for(int i=1;i<=n;++i)
        for(int j=0;j<=1000;++j) dis[i][j]=LLONG_MAX;
    q.push({s,0,cost[1]});
    dis[s][cost[1]]=0;
    while(!q.empty()){
        Node u=q.top();q.pop();
		int x=u.id,y=u.s;
		if(vis[x][y]==1) continue;
		vis[x][y]=1;
		for(auto v:g[x]){
			int len=v.d,e=v.id,f=min(y,cost[e]);
			if(dis[e][f]>dis[x][y]+len*y)
				dis[e][f]=dis[x][y]+len*y,q.push({e,dis[e][f],f});
		}
    }
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;++i){
		g[i].clear();
		for(int j=0;j<=1000;++j) vis[i][j]=0;
	}
    for(int i=0,u,v,w;i<m;++i)
		cin>>u>>v>>w,g[u].push_back({v,w,0}),g[v].push_back({u,w,0});
	for(int i=1;i<=n;++i) cin>>cost[i];
	dijkstra(1);
	int minn=LLONG_MAX;
	for(int i=0;i<=1000;++i) minn=min(minn,dis[n][i]);
    cout<<minn<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
