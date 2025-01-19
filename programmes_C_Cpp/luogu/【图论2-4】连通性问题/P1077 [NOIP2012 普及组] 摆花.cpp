#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
constexpr ll mod=1e6+7;
ll n,m,a[110],dp[110][110];
void solve(){
    cin>>n>>m;
    for(ll i=1;i<=n;++i) cin>>a[i];
    for(ll i=0;i<=n;++i) dp[i][0]=1;
    for(ll i=1;i<=n;++i)
        for(ll j=1;j<=m;++j)
            for(ll k=j;k>=max(j-a[i],0ll);--k) dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
    cout<<dp[n][m];
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}
