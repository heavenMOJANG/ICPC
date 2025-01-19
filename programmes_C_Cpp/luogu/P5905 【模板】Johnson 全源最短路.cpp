#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
typedef pair<ll,ll>PLL;
const ll inf=1e9;
ll dx[]={-1,1,0,0};
ll dy[]={0,0,-1,1};
struct Edge{ll from,to,nxt,w;}edge[600010];
struct Node{
    ll id,dis;
    bool operator<(const Node&x)const{return dis>x.dis;}
};
ll n,m,head[300010],dis[300010],vis[300010],inq[300010],h[300010],idx=1;
void add_edge(ll u,ll v,ll w){edge[idx]={u,v,head[u],w},head[u]=idx++;}
ll spfa(){
    queue<int>q;
    fill(h+1,h+1+n,inf);
    q.push(0);
    vis[0]=1,h[0]=0;
    while(!q.empty()){
        ll u=q.front();q.pop();
        vis[u]=0;
        for(ll i=head[u];~i;i=edge[i].nxt){
            ll v=edge[i].to;
            if(h[v]>h[u]+edge[i].w){
                h[v]=h[u]+edge[i].w;
                if(!vis[v]){
                    q.push(v);
                    vis[v]=1;
                    if(++inq[v]>n) return 0;
                }
            }
        }
    }
    return 1;
}
void dijkstra(ll s){
    priority_queue<Node>q;
    fill(dis+1,dis+1+n,inf);
    memset(vis,0,sizeof(vis));
    q.push({s,0});
    dis[s]=0;
    while(!q.empty()){
        ll u=q.top().id;q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(ll i=head[u];~i;i=edge[i].nxt){
            ll v=edge[i].to;
            if(dis[v]>dis[u]+edge[i].w){
                dis[v]=dis[u]+edge[i].w;
                if(!vis[v]) q.push({v,dis[v]});
            }
        }
    }
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(head,-1,sizeof(head));
    cin>>n>>m;
    for(ll i=1,u,v,w;i<=m;++i) cin>>u>>v>>w,add_edge(u,v,w);
    for(ll i=1;i<=n;++i) add_edge(0,i,0);
    if(!spfa()){cout<<"-1";return 0;}
    for(ll i=1;i<idx;++i) edge[i].w+=h[edge[i].from]-h[edge[i].to];
    for(ll i=1;i<=n;++i){
        dijkstra(i);
        ll res=0;
        for(ll j=1;j<=n;++j){
            if(dis[j]==inf) res+=j*inf;
            else res+=j*(dis[j]-(h[i]-h[j]));
        }
        cout<<res<<"\n";
    }
    return 0;
}
