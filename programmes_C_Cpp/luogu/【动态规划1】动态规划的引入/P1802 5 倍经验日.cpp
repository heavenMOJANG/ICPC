#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,x,dp[1010];
void solve(){
    cin>>n>>x;
    for(ll i=1,lose,win,use;i<=n;++i){
        cin>>lose>>win>>use;
        for(ll j=x;j>=0;--j)
            if(j>=use) dp[j]=max(dp[j]+lose,dp[j-use]+win);
            else dp[j]+=lose;
    }
    cout<<5*dp[x];
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}
