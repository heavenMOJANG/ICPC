#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
constexpr ll N=500010;
ll x,n,a[N],dp[N],d[N],ans1,ans2,len;
void solve(){
    while(cin>>x) a[++n]=x;
    d[++len]=a[1];
	for(ll i=2;i<=n;++i)
		if(d[len]>=a[i]) d[++len]=a[i];
		else{
			ll p=upper_bound(d+1,d+1+len,a[i],greater<ll>())-d;
			d[p]=a[i];
		} 
	ans1=len;
	len=0;
	d[++len]=a[1];
	for(ll i=2;i<=n;++i)
		if(d[len]<a[i]) d[++len]=a[i];
		else{
			ll p=lower_bound(d+1,d+1+len,a[i])-d;
			d[p]=a[i];
		}
	ans2=len;
    cout<<ans1<<"\n"<<ans2;
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}
