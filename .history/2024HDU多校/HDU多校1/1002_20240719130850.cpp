#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
int n,k;
vector<int>dp(4010,LLONG_MAX);
void solve(){
    cin>>n>>k;
    dp[0]=0;
    for(int i=0,a,b,c,d;i<n;++i){
        cin>>a>>b>>c>>d;
        for(int j=k;j>=1;--j){
            if(j>=1) dp[j]=min(dp[j],dp[j-1]+a);
            if(j>=2) dp[j]=min(dp[j],dp[j-2]+b);
            if(j>=3) dp[j]=min(dp[j],dp[j-3]+c);
            if(j>=4) dp[j]=min(dp[j],dp[j-4]+d);
        }
    }
    cout<<dp[k]<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}