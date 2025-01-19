#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
int n,dp[200010],a[200010];
void solve(){
    cin>>n;
    map<int,int>mp;
    for (int i=1;i<=n;++i) cin>>a[i];
    dp[n]=1;dp[n+1]=0;
    for(int i=n-1;i>=1;--i){
        dp[i]=1+dp[i+1];
        if(i+a[i]<=n) dp[i]=min(dp[i], dp[i+a[i]+1]);
    }
    cout<<dp[1]<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
