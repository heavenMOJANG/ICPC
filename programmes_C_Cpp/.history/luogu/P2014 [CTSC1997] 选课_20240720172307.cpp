#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int N=310;
int n,m,dp[N][N],a[N];
vector<int>g[N];
int dfs(int u){
    int p=1;
    dp[u][1]=a[u];
    for(auto v:g[u]){
        int siz=dfs(v);
        for(int i=min(p,m+1);i;--i)
            for(int j=1;j<=siz&&i+j<=m+1;++j)
                dp[u][i+j]=max(dp[u][i+j],dp[u][i]+dp[v][j]);
        p+=siz;
    }
    return p;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1,k;i<=n;++i){
        cin>>k>>a[i];
        g[k].emplace_back(i);
    }
    dfs(0);
    cout<<dp[0][m+1]<<"\n";
    return 0;
}