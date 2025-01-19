#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>a(n+1),dp(n+1);
    int ans=LLONG_MIN;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        dp[i]=a[i];
        if((a[i]+a[i-1])&1) dp[i]=max(dp[i],dp[i-1]+a[i]);
        ans=max(ans,dp[i]);
    }
    cout<<ans<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
