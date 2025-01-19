#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int N=2e5+10;
struct edge{int u,v,w;}e[N];
vector<pii>graph[N];
int n,m,U,V,W,fa[N],vis[N];
vector<int>path;
int cmp(edge a, edge b){return a.w>b.w;}
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void merge(int x,int y){fa[find(x)]=find(y);}
int dfs(int cur){
    if(cur==V) return 1;
    for(auto it:graph[cur]){
        if(it.second<W||vis[it.first]) continue;
        vis[it.first]=1;
        path.push_back(it.first);
        if(dfs(it.first)) return 1;
        path.pop_back();
    }
    return 0;
}
void solve(){
    cin >>n>>m;
    for(int i=1;i<=n;++i) fa[i]=i,graph[i].clear(),vis[i]=0;
    for(int i=1;i<=m;++i) cin>>e[i].u>>e[i].v>>e[i].w;
    path.clear();  
    sort(e+1,e+1+m,cmp);
    for(int i=1;i<=m;++i){
        int u=e[i].u,v=e[i].v,w=e[i].w;
        graph[u].push_back({v,w}),graph[v].push_back({u,w});
        if(find(u)==find(v)) U=u,V=v,W=w;
        else merge(u,v); 
    }
    path.push_back(U);
    vis[U]=1;
    dfs(U);
    cout<<W<<" "<<path.size()<<"\n";
    for(auto it:path) cout<<it<<" ";
    cout << "\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
