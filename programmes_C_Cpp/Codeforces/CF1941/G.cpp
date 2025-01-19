#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,m;cin>>n>>m;
	int idx=n+1;
	map<int,int>mp;
	vector<vector<pair<int,int>>>edge(n+m+10);
	for(int i=1,u,v,w;i<=m;++i){
		cin>>u>>v>>w;
		if(!mp.count(w)) mp[w]=++idx;
		edge[u].push_back({mp[w],1});
		edge[v].push_back({mp[w],1});
		edge[mp[w]].push_back({u,0});
		edge[mp[w]].push_back({v,0});
	}
	int s,t;cin>>s>>t;
	vector<int>dis(n+m+10,LLONG_MAX);
	deque<int>q;
	dis[s]=0;
    q.push_front(s);
	while(!q.empty()){
		auto u=q.front();q.pop_front();
		for(auto [v,w]:edge[u]){
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				if(w) q.push_back(v);
				else q.push_front(v);
			}
		}
	}
	cout<<dis[t]<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
