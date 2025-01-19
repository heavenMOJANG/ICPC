#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,w,f;
void solve(){
    cin>>w>>f>>n;
    ll sum=0;
    vector<ll>a(n);
    for(ll i=0;i<n;++i) cin>>a[i],sum+=a[i];
    vector<ll>dp(sum+10);
    dp[0]=1;
    for(ll i=0;i<n;++i)
        for(ll j=sum;j>=a[i];--j) dp[j]|=dp[j-a[i]];
    ll minn=sum;
    for(ll i=0;i<=sum;++i)
        if (dp[i]) minn=min(minn,max((i+w-1)/w,(sum-i+f-1)/f));
    cout<<minn<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
