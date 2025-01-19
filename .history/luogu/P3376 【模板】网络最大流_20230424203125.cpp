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
struct Edge{ll to,nxt,w;}edge[10010];
ll n,m,s,t,idx=1,head[210],cur[210],dep[210];
void add_edge(ll u,ll v,ll w){edge[++idx]={v,head[u],w},head[u]=idx;}
ll bfs(){
    fill(dep+1,dep+1+n,inf);
    dep[s]=0;
    cur[s]=head[s];
    queue<ll>q;q.push(s);
    while(!q.empty()){
        ll u=q.front();q.pop();
        for(ll i=head[u];~i;i=edge[i].nxt){
            ll v=edge[i].to;
            if(edge[i].w&&dep[v]==inf){
                q.push(v);
                cur[v]=head[v];
                dep[v]=dep[u]+1;
                if(v==t) return 1;
            }
        }
    }
    return 0;
}
ll dfs(ll u,ll sum){
    if(u==t) return sum;
    ll k,flow=0;
    for(ll i=cur[u];i&&sum;i=edge[i].nxt){
        cur[u]=i;
        ll v=edge[i].to;
        if(edge[i].w&&(dep[v]==dep[u]+1)){
            k=dfs(v,min(sum,edge[i].w));
            if(k==0) dep[v]=inf;
            edge[i].w-=k;
            edge[i^1].w+=k;
            flow+=k;
            sum-=k;
        }
    }
    return flow;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(head,-1,sizeof(head));
    cin>>n>>m>>s>>t;
    for(ll i=1,u,v,w;i<=m;++i) cin>>u>>v>>w,add_edge(u,v,w),add_edge(v,u,0);
    ll res=0;
    while(bfs()) res+=dfs(s,inf);
    cout<<res;
    return 0;
}