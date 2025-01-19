#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll t,m,dp[10000010];
void solve(){
    cin>>t>>m;
    for(ll i=1,a,b;i<=m;++i){
        cin>>a>>b;
        for(ll j=a;j<=t;++j) dp[j]=max(dp[j],dp[j-a]+b);
    }
    cout<<dp[t];
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}
