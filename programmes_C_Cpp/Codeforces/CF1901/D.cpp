#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>a(n+1);
	for(int i=1;i<=n;++i) cin>>a[i];
    vector<int>l(n+10,0),r(n+10,0);
	for(int i=1;i<=n;++i){
		l[i]=a[i]+i-1;
		r[i]=a[i]+n-i;
	}
	for(int i=1;i<=n;++i)
		r[i]=max(r[i-1],r[i]);
	for(int i=n;i>=1;--i)
		l[i]=max(l[i+1],l[i]);
	int ans=LLONG_MAX;
	for(int i=1;i<=n;++i) ans=min(ans,max(a[i],max(r[i-1],l[i+1])));
	cout<<ans<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
