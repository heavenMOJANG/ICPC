#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
typedef pair<ll,ll>PLL;
const ll inf=0x3f3f3f3f;
ll dx[]={-1,1,0,0};
ll dy[]={0,0,-1,1};
struct Edge{ll to,nxt,w=1;}edge[200010];
struct Node{
    ll id,dis;
    bool operator<(const Node&x)const{return dis>x.dis;}
};
ll n,d,head[100010],vis[100010],dis[100010],idx,cnt;
void add_edge(ll u,ll v){edge[idx]={v,head[u]},head[u]=idx++;}
void Dijkstra(ll s){
    fill(dis+1,dis+1+n,inf);
    priority_queue<Node>q;
    q.push({s,dis[s]=0});
    while(!q.empty()){
        ll u=q.top().id;q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(ll i=head[u];~i;i=edge[i].nxt){
            ll v=edge[i].to;
            if(dis[v]>dis[u]+edge[i].w) q.push({v,dis[v]=dis[u]+edge[i].w});
        }
    }
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(head,-1,sizeof(head));
    cin>>n>>d;
    for(ll i=1,u,v;i<n;++i) cin>>u>>v,add_edge(u,v),add_edge(v,u);
    Dijkstra(1);
    for(ll i=2;i<=n;++i) if(dis[i]<=d) cnt++;
    cout<<cnt;
    return 0;
}