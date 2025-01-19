#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int N=100010;
struct edge{
    int to,nxt,w;
}edge[N<<1];
int n,head[N],idx,dis[N],trie[N<<5][2],tot=1,ans;
void addEdge(int u,int v,int w){
    edge[++idx]={v,head[u],w};
    head[u]=idx;
}
void insert(int x){
    for(int i=30,u=1;i>=0;--i){
        int c=(x>>i)&1;
        if(!trie[u][c]) trie[u][c]=++tot;
        u=trie[u][c];
    }
}
void get(int x){
    int res=0;
    for(int i=30,u=1;i>=0;--i){
        int c=(x>>i)&1;
        if(trie[u][c^1]){
            u=trie[u][c^1];
            res|=1ll<<i;
        }
        else u=trie[u][c];
    }
    ans=max(ans,res);
}
void dfs(int u,int fa){
    insert(dis[u]);
    get(dis[u]);
    for(int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(v==fa) continue;
        dis[v]=dis[u]^edge[i].w;
        dfs(v,u);
    }
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n-1;++i){
        int u,v,w;cin>>u>>v>>w;
        addEdge(u,v,w);
        addEdge(v,u,w);
    }
    dfs(1,0);
    cout<<ans<<"\n";
    return 0;
}