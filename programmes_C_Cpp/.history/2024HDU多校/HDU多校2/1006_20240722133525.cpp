#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>g[n+1];
    vector<pair<int,int>>v;
    for(int i=1;i<=n;++i){
        cin>>v[i].second;
        v[i].first=15;
    }
    for(int i=0,u,v;i<n-1;++i){
        cin>>u>>v;
        g[u].emplace_back(v);
    }
    function<void(int)> dfs=[&](int u){
        for(auto v:g[u]){
            dfs(v);

        }
    };
    dfs(1);
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}