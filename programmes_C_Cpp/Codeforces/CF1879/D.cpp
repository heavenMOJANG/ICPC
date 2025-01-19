#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
constexpr ll mod=998244353;
ll n,a[300010],b[300010][31],sum[300010],f[300010];
void solve(){
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>a[i];
    ll res=0;
    for(ll i=0;i<=30;++i){
		ll tmp0=1,tmp1=0,num0=1,num1=0;
		for(ll j=1;j<=n;++j){
			if(a[j]&(1ll<<i)) b[j][i]=1;
			sum[j]=sum[j-1]^b[j][i];
		}
		for(ll j=1;j<=n;++j){
			if(sum[j]) res=(res+tmp0*((1ll<<i)%mod))%mod;
			else res=(res+tmp1*((1ll<<i)%mod))%mod;
			if(!sum[j]) num0++;
			else num1++;
			(tmp0+=num0)%=mod;
			(tmp1+=num1)%=mod;
		}
	}
    cout<<res<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}
