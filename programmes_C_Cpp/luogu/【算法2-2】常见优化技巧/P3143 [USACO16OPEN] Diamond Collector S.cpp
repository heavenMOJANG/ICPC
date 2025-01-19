#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,k;
void solve(){
    cin>>n>>k;
    vector<ll>a(n+1),qL(n+1),qR(n+1);
    for(ll i=1;i<=n;++i) cin>>a[i];
    sort(++a.begin(),a.end());
    ll l=1;
    qL[1]=1;
    for(ll i=2;i<=n;++i){
		while(a[i]-a[l]>k) l++;
		qL[i]=max(qL[i-1],i-l+1);
	}
	ll r=n;
	qR[n]=1;
	for (ll i=n-1;i>=1;--i){
		while(a[r]-a[i]>k) r--;
		qR[i]=max(qR[i+1],r-i+1);
	}
	ll res=0;
	for(ll i=1;i<n;++i) res=max(res,qL[i]+qR[i+1]);
    cout<<res;
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}
