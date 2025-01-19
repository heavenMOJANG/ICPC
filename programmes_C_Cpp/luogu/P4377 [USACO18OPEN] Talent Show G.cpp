#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
struct{ll w,t;double y;}cow[260];
ll n,w;
double dp[1010];
ll check(double x){
    for(ll i=1;i<=n;++i) cow[i].y=(double)cow[i].t-x*cow[i].w;
    for(ll i=1;i<=w;++i) dp[i]=-inf;
    dp[0]=0;
    for(ll i=1;i<=n;++i)
        for(ll j=w;j>=0;--j)
            if(j+cow[i].w>=w) dp[w]=max(dp[w],dp[j]+cow[i].y);
            else dp[j+cow[i].w]=max(dp[j+cow[i].w],dp[j]+cow[i].y);
    return dp[w]<0;
}
void solve(){
    cin>>n>>w;
    for(ll i=1;i<=n;++i) cin>>cow[i].w>>cow[i].t;
    double l=0,r=0;
    for(ll i=1;i<=n;++i) r+=cow[i].t;
    for(ll i=0;i<50;++i){
        double mid=l+(r-l)/2;
        if(check(mid)) r=mid;
        else l=mid;
    }
    cout<<(int)(l*1000)<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}
