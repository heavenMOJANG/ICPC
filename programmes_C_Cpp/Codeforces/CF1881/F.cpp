#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
vector<int>a[200010];
int n,k,vis[200010],vis2[200010],dis[200010],pos;
void bfs(int x){
    fill(vis,vis+1+n,0);
    fill(dis,dis+1+n,0);
    pos=x;
    vis[x]=1,dis[x]=0;
    queue<int>q;
    q.push(x);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=0;i<a[u].size();++i)
            if(!vis[a[u][i]]){
                vis[a[u][i]]=1;
                dis[a[u][i]]=dis[u]+1;
                q.push(a[u][i]);
                if(dis[a[u][i]]>dis[pos]&&vis2[a[u][i]]) pos=a[u][i];
            }
    }
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;++i) vis2[i]=0,a[i].clear();
    for(int i=1,x;i<=k;++i){
        cin>>x;
        vis2[x]=1;
        pos=x; 
    }
    for(int i=1,x,y;i<n;++i){
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    if(k==1){cout<<"0\n";return;}
    bfs(pos);
    bfs(pos);
    cout<<(dis[pos]+1)/2<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
