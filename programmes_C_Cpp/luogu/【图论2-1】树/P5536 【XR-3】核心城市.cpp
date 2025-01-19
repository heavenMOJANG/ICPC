#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
struct Edge{ll to,nxt;}e[200010];
ll n,k,head[100010],idx,vis[100010],dis[100010],dep[100010],maxd[100010],X,p,pl[100010],minn=-1,ans[100010];
void addEdge(ll u,ll v){e[idx]={v,head[u]},head[u]=idx++;}
void bfs(ll s){
    memset(dis,0,sizeof(dis));
    memset(vis,0,sizeof(vis));
    queue<ll>q;
    q.push(s);
    vis[s]=1;
    while(!q.empty()){
        ll u=q.front();q.pop();
        for(ll i=head[u];~i;i=e[i].nxt){
            ll v=e[i].to;
            if(!vis[v]){
                pl[v]=u;
                dis[v]=dis[u]+1;
                q.push(v);
                vis[v]=1;
            }
        }
    }
    X=0;
    for(ll i=1;i<=n;++i) if(dis[i]>X) X=dis[i],p=i;
}
void dfs(ll u,ll fa){
    maxd[u]=dep[u];
    for(ll i=head[u];~i;i=e[i].nxt){
        ll v=e[i].to;
        if(v==fa) continue;
        dep[v]=dep[u]+1;
        dfs(v,u);
        maxd[u]=max(maxd[u],maxd[v]);
    }
}
void solve(){
    memset(head,-1,sizeof(head));
    cin>>n>>k;
    for(ll i=1,u,v;i<n;++i) cin>>u>>v,addEdge(u,v),addEdge(v,u);
    bfs(1);bfs(p);
    ll central=p;
    for(ll i=1;i<=X+1>>1;++i) central=pl[central];
    dfs(central,0);
    for(ll i=1;i<=n;++i) ans[i]=maxd[i]-dep[i];
    sort(ans+1,ans+1+n,[](const ll&x,const ll&y){return x>y;});
    for(ll i=k+1;i<=n;++i) minn=max(ans[i]+1,minn);
    cout<<minn;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}