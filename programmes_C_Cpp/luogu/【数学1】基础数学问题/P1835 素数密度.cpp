#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
const ll N=1e6+10;
ll l,r,is[1000010],prime[1000010],vis[1000010],idx;
void Euler(){
	for(ll i=2;i<=1000000;++i){
		if(!vis[i]) prime[idx++]=i;
		for(ll j=0;j<idx;++j){
			if(prime[j]*i>=N) break;
			vis[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
}
ll solve(){
	ll res=0;
	for(ll i=0;i<idx;++i){
		ll pr=prime[i],sta=l;
		if(pr>r) break;
		if(pr>=l) for(ll j=pr*2;j<=r;j+=pr) is[j-l]=1;
		else{
			if(l%pr!=0) sta=l/pr*pr+pr;
			for(ll j=sta;j<=r;j+=pr) is[j-l]=1;
		}
	}
	for(ll i=l;i<=r;++i) if(is[i-l]==0 && i!=1) res++;
	return res;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    Euler();
    cin>>l>>r;
    cout<<solve();
    return 0;
}