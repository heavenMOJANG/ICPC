#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
void solve(){
    ll n,a,b;cin>>n>>a>>b;
    vector<ll>g[n+10],ind(n+10,0),c(n+10),p;
    for(ll i=1,u,v;i<=n;++i) cin>>u>>v,g[u].push_back(v),g[v].push_back(u),ind[u]++,ind[v]++;
    if(a==b){cout<<"NO\n";return;}
    queue<ll>q;
    for(ll i=1;i<=n;++i) if(ind[i]==1) q.push(i);
    while(!q.empty()){
        ll u=q.front();q.pop();
        for(auto v:g[u]){
            if(--ind[v]==1) q.push(v);
        }
    }
    for(ll i=1;i<=n;++i) if(ind[i]>1) c[i]=1,p.push_back(i);
    if(c[b]){cout<<"YES\n";return;}
    vector<ll>disa(n+10),disb(n+10),vis(n+10,0);
    disa[a]=disb[b]=0;
	q.push(a);
	while(!q.empty()){
	    ll u=q.front();q.pop();
		vis[u]=1;
		for(auto v:g[u])
			if(!vis[v]){
				disa[v]=disa[u]+1;
				vis[v]=1;
				q.push(v);
			}
	}
    fill(vis.begin(),vis.end(),0);
    q.push(b);
    while(!q.empty()){
	    ll u=q.front();q.pop();
		vis[u]=1;
		for(auto v:g[u])
			if(!vis[v]){
				disb[v]=disb[u]+1;
				vis[v]=1;
				q.push(v);
			}
	}
    for(ll i=0;i<p.size();++i) if(disb[p[i]]<disa[p[i]]){cout<<"YES\n";return;}
    cout<<"NO\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
