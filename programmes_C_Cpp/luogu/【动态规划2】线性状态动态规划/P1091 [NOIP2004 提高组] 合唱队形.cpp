#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,a[110],dp1[110],dp2[110],maxn;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>a[i];
    dp1[1]=1;
	for(ll i=2;i<=n;++i){
        dp1[i]=1;
		for(ll j=1;j<i;++j) if(a[i]>a[j]) dp1[i]=max(dp1[i],dp1[j]+1);
    }
    dp2[n]=1;
	for(ll i=n-1;i>=1;--i){
        dp2[i]=1;
		for(ll j=n;j>i;--j) if(a[i]>a[j]) dp2[i]=max(dp2[i],dp2[j]+1);
    }
    for(ll i=1;i<=n;++i) maxn=max(maxn,dp1[i]+dp2[i]-1);
	cout<<n-maxn;
    return 0;
}