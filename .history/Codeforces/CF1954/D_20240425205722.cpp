#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int mod=998244353;
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    sort(a.begin(), a.end());
    vector<int>dp(5010);
    int ans=0;
    dp[0]=1;
    for(int i=0;i<n;++i){
        for(int j=a[i];j<=5000;++j) ans=(ans+dp[j-a[i]]*max(a[i],(j+1)/2)%mod)%mod;
        for(int j=5000;j>=a[i];--j) dp[j]=(dp[j]+dp[j-a[i]])%mod;
    }
    cout<<(ans%mod+mod)%mod<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;//cin>>_;
    while(_--) solve();
    return 0;
}