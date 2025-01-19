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
struct Edge{ll to,nxt,w;}edge[50010];
ll n,m,head[1510],vis[1510],dis[1510],idx,inq[1510],neg[1510],pre[1510];
void add(ll u,ll v,ll w){edge[idx]={v,head[u],w},head[u]=idx++;}
void spfa(ll s){
    queue<ll>q;
    q.push(s);
    dis[s]=0;vis[s]=1;;
    while(!q.empty()){
        ll u=q.front();q.pop();
        vis[u]=0;
        for(ll i=head[u];~i;i=edge[i].nxt){
            ll v=edge[i].to;
            if(dis[v]>dis[u]+edge[i].w){
                dis[v]=dis[u]+edge[i].w;
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(head,-1,sizeof(head));
    cin>>n>>m;
    for(ll i=1;i<=n;++i) dis[i]=inf;
    for(ll i=1;i<=m;++i){ll u,v,w; cin>>u>>v>>w,add(u,v,-w);}
    spfa(1);
    if(dis[n]==inf) dis[n]=1;
    cout<<-dis[n];
    return 0;
}