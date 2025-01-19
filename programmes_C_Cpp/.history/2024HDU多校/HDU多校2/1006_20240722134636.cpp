#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>g[n+1];
    vector<pair<int,int>>a(n+1);
    for(int i=0,u,v;i<n-1;++i){
        cin>>u>>v;
        g[u].emplace_back(v);
    }
    for(int i=1,p;i<=n;++i){
        cin>>p;
        a[i]={15,p};
    }
    function<void(int)> dfs=[&](int u){
        pair<int,int>maxn={1,1};
        for(auto v:g[u]){
            dfs(v);
            if(a[v].first*maxn.second>a[v].second*maxn.first) maxn=a[v];
        }
        int lcm=maxn.second*a[u].second/__gcd(maxn.second,a[u].second);
        int k1=lcm/maxn.second,k2=lcm/a[u].second;
        maxn.first*=k1,a[u].first=k2;
        a[u].first+=maxn.first;
        int gcd=__gcd(a[u].first,a[u].second);
        a[u].first/=gcd,a[u].second/=gcd;
    };
    dfs(1);
    cout<<a[1].first<<"/"<<a[1].second<<"\n";
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}