#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
const ll mod=1e9+7,inv=5e8+4;
ll n,m,a[510],dp[510][510],res;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=m;++i) dp[i][i]=i;
    for(ll i=1;i<=n;++i) cin>>a[i],res=(res+m-a[i]+1)%mod;
    for(ll i=2;i<=m;++i)
		for(ll j=1;j<=i-1;++j)
			dp[i][j]=inv*(dp[i-1][j]+dp[i][j-1])%mod;
	for(ll i=1;i<n;++i)
		res=(res-dp[m+1-a[i]][m+1-a[i+1]])%mod,res=(res+mod)%mod;
    cout<<res;
    return 0;
}
