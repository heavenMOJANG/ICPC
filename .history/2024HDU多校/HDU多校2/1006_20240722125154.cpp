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
    for(int i=0,u,v;i<n-1;++i){
        cin>>u>>v;
        g[u].emplace_back(v);
    }
    vector<int>dp(n+1);
    function<void(int,int)> dfs=[&](int u,int fa){
        for(int)
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