#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=0x3f3f3f3f;
struct Node{
    ll id,d;
    bool operator<(const Node&x)const{return d>x.d;}
};
struct Edge{ll to,nxt,w;}edge[200010];
ll n,m,b,f[100010],vis[100010],head[100010],idx,dis[100010],l=LLONG_MAX,r;
void add_edge(ll u,ll v,ll w){edge[idx]={v,head[u],w},head[u]=idx++;}
ll check(ll cst){
    if(f[1]>cst) return 0;
    fill(dis+1,dis+1+n,inf);
    fill(vis+1,vis+1+n,0);
    priority_queue<Node>q;
    q.push({1,dis[1]=0});
    while(!q.empty()){
        ll u=q.top().id;q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(ll i=head[u];~i;i=edge[i].nxt){
            ll v=edge[i].to;
            if(dis[v]>dis[u]+edge[i].w&&f[v]<=cst){
                dis[v]=dis[u]+edge[i].w;
                q.push({v,dis[v]});
            }
        }
    }
    return dis[n]<=b;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(head,-1,sizeof(head));
    cin>>n>>m>>b;
    for(ll i=1;i<=n;++i) cin>>f[i],l=min(l,f[i]),r=max(r,f[i]);
    for(ll i=1,u,v,w;i<=m;++i) cin>>u>>v>>w,add_edge(u,v,w),add_edge(v,u,w);
    if(!check(r)) return cout<<"AFK",0;
    while(l<r){
        ll mid=l+r>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<l;
    return 0;
}
