#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,k,a[1010];
ll check(ll x,ll p){
    ll cnt=0,cur=x,flag=0;
    for(ll i=p;i<=n;++i){
        if(a[i]>=cur){flag=1;break;}		
		cnt+=cur-a[i];
		cur--;
	}
	if(flag&&cnt<=k) return 1;
	return 0;
}
void solve(){
    cin>>n>>k;
    ll maxn=0;
    for(ll i=1;i<=n;++i) cin>>a[i],maxn=max(maxn,a[i]);
    for(ll i=1;i<=n;++i){
		ll l=a[i],r=1e18;
		while(l<r){
			ll mid=l+r+1>>1;
			if(check(mid,i)) l=mid;
			else r=mid-1;
		}
		maxn=max(maxn,l);
	}
    cout<<maxn<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}