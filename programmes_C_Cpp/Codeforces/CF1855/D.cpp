#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
ll _,n,a[100010],s[100010],res;
bitset<200010>dp;
void solve(){
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>a[i],s[i]=s[i-1]+a[i];
    dp[a[1]]=1,dp[0]=0;
    res+=a[1];
    for(ll i=2;i<=n;++i){
        if(dp[i-1]) res=max(res,s[i]-i+1);
        dp|=dp<<a[i];
        dp[i-1]=0;
    }
    for(ll i=n;i<n*2;++i) if(dp[i]) res=max(res,s[n]-i);
    cout<<res;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    _=1;
    while(_--) solve();
    return 0;
}
