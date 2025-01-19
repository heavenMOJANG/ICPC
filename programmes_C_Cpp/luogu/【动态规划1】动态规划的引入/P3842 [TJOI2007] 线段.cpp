#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
constexpr ll N=20010;
struct{ll l,r;}a[N];
ll n,dp[N][2],b[N];
void solve(){
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>a[i].l>>a[i].r,b[i]=a[i].r-a[i].l;
    dp[1][1]=abs(a[1].r-1);
    dp[1][0]=dp[1][1]+b[1];
    for(ll i=2;i<=n;++i){
        dp[i][0]=min(dp[i-1][0]+b[i]+abs(a[i-1].l-a[i].r),dp[i-1][1]+b[i]+abs(a[i-1].r-a[i].r))+1;
        dp[i][1]=min(dp[i-1][0]+b[i]+abs(a[i-1].l-a[i].l),dp[i-1][1]+b[i]+abs(a[i-1].r-a[i].l))+1;
    }
    cout<<min(dp[n][0]+abs(n-a[n].l),dp[n][1]+abs(n-a[n].r));
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}
