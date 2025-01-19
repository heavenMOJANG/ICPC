#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int N=5e5+10;
int n;
vector<int>a(N),g[N];
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    for(int i=0,u,v;i<n-1;++i){
        cin>>u>>v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for(int i=1;i<=n;++i) cin>>a[i];
    
    return 0;
}