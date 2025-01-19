#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[1010],dp[1010],maxn=LLONG_MIN;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>a[i];
    for(ll i=1;i<n;++i){
        dp[i]=1;
        for(ll j=1;j<i;++j) if(a[i]>=a[j]&&(dp[j]+1>dp[i])) dp[i]=dp[j]+1;
        maxn=max(maxn,dp[i]);
    }
    cout<<maxn;
    return 0;
}