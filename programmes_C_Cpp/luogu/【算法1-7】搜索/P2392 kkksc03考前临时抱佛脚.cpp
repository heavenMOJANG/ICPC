#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll s[4],dp[10000],a[4][50],sum,res;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>s[0]>>s[1]>>s[2]>>s[3];
	for(ll i=0;i<4;++i){
        sum=0;
		memset(dp,0,sizeof(dp));
		for(ll j=0;j<s[i];++j) cin>>a[i][j],sum+=a[i][j];
		for(ll j=0;j<s[i];++j)
			for(ll k=sum/2;k>=a[i][j];--k) dp[k]=max(dp[k],dp[k-a[i][j]]+a[i][j]);
		res+=sum-dp[sum/2];
	}
    cout<<res;
    return 0;
}