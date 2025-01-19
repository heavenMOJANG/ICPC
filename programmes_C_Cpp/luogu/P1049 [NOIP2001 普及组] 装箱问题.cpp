#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll v,n,dp[20010];
void solve(){
    cin>>v>>n;
    for(ll i=1,x;i<=n;++i){
        cin>>x;
        for(ll j=v;j>=x;--j) dp[j]=max(dp[j],dp[j-x]+x);
    }
    cout<<v-dp[v];
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}
