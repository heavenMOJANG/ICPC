#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,k;cin>>n>>k;
    vector<int>a(n+1);
    for(int i=1;i<=n;++i) cin>>a[i];
    vector<vector<int>>dp(n+1,vector<int>(k+1));
    for(int i=1;i<=n;++i) dp[i][0]+=dp[i-1][0];
    for(int i=1;i<=n;++i){
        dp[i][j]=dp[i-1][j]+a[i];
        dp[i][j+1]=dp[i-1][j]-a[i]+min(a[i-1],a[i+1]);
    }
    cout<<dp[n][k]<<"\n";
    return;
}
signed main(){
    std::cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}