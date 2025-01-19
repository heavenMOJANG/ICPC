#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,m;cin>>n>>m;
    vector<pii>g[n+1];
    vector<int>dfn(n+1),low(n+1),siz(n+1),vis(n+1);
    stack<int>s;
    int minn=LLONG_MAX,idx=0,cnt=0;
    for(int i=1,u,v;i<=m;++i){
        cin>>u>>v;
        g[u].push_back({v,i});
        g[v].push_back({u,i});
    }
    function<void(int,int)> tarjan=[&](int x,int id){
        dfn[x]=low[x]=++idx;
        s.push(x);
        for(auto [y,id2]:g[x]){
            if(!dfn[y]){
                tarjan(y,id2);
                low[x]=min(low[x],low[y]);
            }
            else if(id!=id2) low[x]=min(low[x],low[y]);
        }
        if(dfn[x]==low[x]){
            cnt++;
            while(1){
                int y=s.top();s.pop();
                if(x==y) break;
            }
            minn=min(minn,siz[x]*(siz[x]-1)/2+(n-siz[x])*(n-siz[x]-1)/2);
        }
    };
    function
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}