#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
void solve(){
    ll n;cin>>n;
	vector<ll>g[n+1];
	vector<ll>a(n+1),ans(n+1),sz(n+1);
	for(ll i=1;i<=n;++i) cin>>a[i];
	for(ll i=1,u,v;i<n;++i){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	function<void(ll,ll)>dfs1=[&](ll u,ll fa)->void{
		sz[u]=1;
		for(auto v:g[u]){
			if(v==fa) continue;
			dfs1(v,u);
			sz[u]+=sz[v];
			ans[u]+=ans[v]+(a[u]^a[v])*sz[v];
		}
	};
	function<void(ll,ll)>dfs2=[&](ll u,ll fa)->void{
		for(auto v:g[u]){
			if(v==fa) continue;
			ans[v]=ans[u]+(a[u]^a[v])*(n-sz[v]*2);
			dfs2(v,u);
		}
	};
	dfs1(1,1);
	dfs2(1,1);
	for(ll i=1;i<=n;++i) cout<<ans[i]<<" \n"[i==n];
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
