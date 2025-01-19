#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int N=500010;
struct Edge{int to,nxt;}e[N<<1];
int x,n,head[N],idx;
map<int,int>mp;
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>x>>n;
    fill(head,head+N,-1);
    auto addEdge=[&](int u,int v){e[idx]={v,head[u]},head[u]=idx++;};
    for(int i=1,u,v;i<n;++i) cin>>u>>v,addEdge(u,v),addEdge(v,u);
    int ans=0;
    function<void(int,int)> dfs=[&](int u,int fa){
        set<int>s;
        for(int i=1;i<=sqrt(u);++i) if(u%i==0) s.insert(i),s.insert(u/i);
        for(auto &x:s) mp[x]++;
        ans+=mp[u];
        for(int i=head[u];~i;i=e[i].nxt){
            int v=e[i].to;
            if(v==fa) continue;
            dfs(v,u);
        }
        for(auto &x:s) mp[x]--;
    };
    dfs(x,-1);
    cout<<ans<<"\n";
    return 0;
}