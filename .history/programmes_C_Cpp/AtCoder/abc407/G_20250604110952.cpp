#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
const ll inf=0x3f3f3f3f;
const ll N=5010;
const ll M=50010;
ll dx[]={-1,1,0,0};
ll dy[]={0,0,-1,1};
struct Edge{ll to,nxt,f,w;}edge[2*M];
ll n,m,s,t,maxflow,mincost,dis[N],vis[N];
ll head[N],idx=1,cur[N];
void add_edge(ll u,ll v,ll f,ll c){
	edge[++idx]={v,head[u],f,c},head[u]=idx;
	edge[++idx]={u,head[v],0,-c},head[v]=idx;
}
bool spfa(){
    queue<ll>q;q.push(s);
	fill(dis+1,dis+1+n,inf);
    dis[s]=0;
    while(!q.empty()){
        ll u=q.front();q.pop();
        vis[u]=0;
        for(ll i=head[u];i;i=edge[i].nxt){
			ll v=edge[i].to;
            if(edge[i].f&&dis[u]+edge[i].w<dis[v]){
                dis[v]=dis[u]+edge[i].w;
                if(!vis[v]) q.push(v),vis[v]=1;
			}
        }
    }
    return dis[t]!=inf;
}
ll dfs(ll u,ll flow){
    if(u==t){maxflow+=flow;return flow;}
    ll res=0;
	vis[u]=1;
    for(ll i=cur[u];i;i=edge[i].nxt){
		ll v=edge[i].to;
        if(!vis[v]&&edge[i].f&&dis[v]==dis[u]+edge[i].w){
        	cur[u]=i;
            ll p=dfs(v,min(flow-res,edge[i].f));
            res+=p,edge[i].f-=p,edge[i^1].f+=p,mincost+=p*edge[i].w;
            if(res==flow) break;
        }
    }
    vis[u]=0;
    return res;
}
void dinic(){
    while(spfa()){
    	memcpy(cur,head,sizeof(head));
    	dfs(s,inf);
	}
}

int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>s>>t;
    for(ll i=1,u,v,f,w;i<=m;++i){
		cin>>u>>v>>f>>w;
        add_edge(u,v,f,w);
    }
    dinic();
	cout<<maxflow<<" "<<mincost;
    return 0;
}
