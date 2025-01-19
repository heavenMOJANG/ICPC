#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
typedef pair<ll,ll>PLL;
const ll inf=0x3f3f3f3f;
ll dx[]={-1,1,0,0};
ll dy[]={0,0,-1,1};
struct Edge{ll to,nxt;}edge[2000010];
struct Node{
    ll id,d;
    bool operator<(const Node&x)const{return d>x.d;}
};
ll n,m,head[1000010],vis[1000010],dis[1000010],dp[1000010],idx;
void add_edge(ll u,ll v){edge[idx]={v,head[u]},head[u]=idx++;}
void Dijkstra(ll s){
    priority_queue<Node>q;
    q.push({s,dis[s]=0});
    while(!q.empty()){
        ll u=q.top().id;q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(ll i=head[u];~i;i=edge[i].nxt){
            ll v=edge[i].to;
            if(dis[v]>dis[u]+1){
                dis[v]=dis[u]+1;
                dp[v]=dp[u];
                q.push({v,dis[v]});
            }
            else if(dis[v]==dis[u]+1) dp[v]=(dp[v]+dp[u])%100003;
        }
    }
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(head,-1,sizeof(head));
    memset(dis,0x3f,sizeof(dis));
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=m;++i){
        ll x,y;cin>>x>>y;
        add_edge(x,y);
        add_edge(y,x);
    }
    dp[1]=1;
    Dijkstra(1);
    for(ll i=1;i<=n;++i) cout<<dp[i]<<"\n";
    return 0;
}