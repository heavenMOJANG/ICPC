#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int mod=1e9+7;
void solve(){
    int n,k; cin>>n>>k;
	vector<int>a(n+1);
	int ans=0,mx=0,mn=0;
	for(int i=1;i<=n;++i) cin>>a[i],ans+=a[i],a[i]+=a[i-1];
	for(int i=1;i<=n;++i){
		mx=max(mx,a[i]-a[mn]);
		if(a[i]<a[mn]) mn=i;
	}
	ans-=mx;
	for(int i=1;i<=k;++i) mx=mx*2ll%mod;
	cout<<((ans%mod)+mx+mod)%mod<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
