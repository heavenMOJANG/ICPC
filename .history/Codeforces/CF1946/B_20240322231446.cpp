#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int mod=1e9+7;
void solve(){
    int n,k;cin>>n>>k;
    vector<int>a(n);
    int res=0;
    for(int i=0;i<n;++i) cin>>a[i],res+=a[i];
    int ans=a[1],sum=0;
	for(int i=0;i<n;++i){
		sum=max(sum+a[i],a[i]);
		ans=max(ans,sum);
	}
    auto get=[&](int x){
        if(x>=0) return x%mod;
        x=-x;
        int d=x/mod+1;
        return d*mod-x;
    };
    if(ans>=0) for(int i=0;i<k;++i) if(res+ans<0) res+=ans;else res=get(res+ans);
    res=get(res);
    cout<<res<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
