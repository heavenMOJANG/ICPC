#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
typedef pair<ll,ll>PLL;
ll dx[]={-1,1,0,0};
ll dy[]={0,0,-1,1};
ll n,m,vis[100010];
vector<ll>g[100010];
void dfs(ll u){
    cout<<u<<" ";
    vis[u]=1;
    for(ll i=0;i<g[u].size();++i){
        ll v=g[u][i];
        if(!vis[v]){
            dfs(v);
            vis[v]=1;
        }
    }
}
void bfs(ll u){
    queue<ll>q;
    vis[u]=1;
    q.push(u);
    cout<<u<<" ";
    while(!q.empty()){
        u=q.front();q.pop();
        for(ll i=0;i<g[u].size();++i){
            ll v=g[u][i];
            if(!vis[v]){
                cout<<v<<" ";
                q.push(v);
                vis[v]=1;
            }
        }
    }
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=m;++i){
        ll u,v; cin>>u>>v;
        g[u].push_back(v);
    }
    for(ll i=1;i<=n;++i) sort(g[i].begin(),g[i].end());
    dfs(1);cout<<"\n";    
    memset(vis,0,sizeof(vis));
    bfs(1);
    return 0;
}