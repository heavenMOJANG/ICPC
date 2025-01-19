#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,k;cin>>n>>k;
	vector<vector<int>>edge(n+1);
	for(int i=1;i<=n-1;++i){
		int u,v;cin>>u>>v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	auto check=[&](int mid)->bool{
		vector<int>sz(n+1);
		int res=0;
		function<void(int,int)> dfs=[&](int u,int fa){
			sz[u]=1;
			for(auto v:edge[u]){
				if(v==fa) continue;
				dfs(v,u);
				if(sz[v]>=mid){res++;continue;}
				sz[u]+=sz[v];
			}
		};		
		dfs(1,-1);
		if(sz[1]<mid) return (res-1)>=k;
		return res>=k;
	};
	int l=0,r=n+1;
	while(l+1!=r){
		int mid = (l+r)>>1;
		if(check(mid)) l=mid;
		else r=mid;
	}
	cout<<l<<endl;
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
