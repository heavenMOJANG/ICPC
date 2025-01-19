#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
constexpr int inf=0x7fffffff;
int idx;
void solve(){
    int n,k,m;cin>>n>>k>>m;
    vector<double>dp(1010),p(1010);
    for(int i=0;i<n;++i) cin>>p[i];
    dp[1]=p[0];
    for(int i=2;i<=m;++i){
        dp[i]=0.0;
        for(int j=0;j<n;++j) dp[i]+=p[j]*pow(dp[i-1],j);
    }
    double ans=pow(dp[m],k);
    cout<<"Case #"<<++idx<<": "<<fixed<<setprecision(8)<<ans<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
