#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
	vector<int>a(n),d(n),l(n,-1),r(n,-1),ans(n),vis(n);
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<n;++i) cin>>d[i];
	for(int i=0;i<n;++i){
		if(i!=0) l[i]=i-1;
		if(i!=n-1) r[i]=i+1;
	}
	auto check=[&](int x){
		int sum=0;
		if(l[x]!=-1) sum+=a[l[x]];
		if(r[x]!=-1) sum+=a[r[x]];
		return !vis[x]&&sum>d[x];
	};
	auto del=[&](int x){
		vis[x]=1;
		if(l[x]!=-1) r[l[x]]=r[x];
		if(r[x]!=-1) l[r[x]]=l[x];
	};
	set<int>s1;
	for(int i=0;i<n;++i) if(check(i)) s1.insert(i);
	for(int i=0;i<n;++i){
		ans[i]=s1.size();
		set<int>s2;
		for(auto v:s1) del(v);
		for(auto v:s1){
			if(l[v]!=-1&&check(l[v])) s2.insert(l[v]);
			if(r[v]!=-1&&check(r[v])) s2.insert(r[v]);
		}
		s1=s2;
	}
    for(int i=0;i<n;++i) cout<<ans[i]<<" \n"[i==n-1];
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
