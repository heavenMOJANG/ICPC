#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x7f;
ll n;
double dp[20][1<<15],x[20],y[20],res;
double dis(ll l,ll r){return sqrt((x[l]-x[r])*(x[l]-x[r])+(y[l]-y[r])*(y[l]-y[r]));}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(dp,inf,sizeof(dp));
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>x[i]>>y[i];
	for (ll i=1;i<(1<<n);++i)
    	for(ll j=1;j<=n;++j){
    		if(!(i&(1<<(j-1)))) continue;
    		if (i==1<<(j-1)){dp[j][i]=0;continue;}
    		for(ll k=1;k<=n;++k)
			    if((i&1<<(k-1))&&(k!=j)) dp[j][i]=min(dp[j][i],dp[k][i-(1<<(j-1))]+dis(j,k));
    	}  
    res=dp[1][(1<<n)-1]+dis(1,0);  
    for(ll i=2;i<=n;i++) res=min(res,dp[i][(1<<n)-1]+dis(i,0));
    cout<<fixed<<setprecision(2)<<res;
    return 0;
}