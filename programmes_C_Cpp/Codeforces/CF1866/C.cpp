#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
constexpr ll mod=998244353;
ll n,res[200010],dp[200010][2],vis[200010];
vector<pair<ll,ll>>g[200010];
void dfs(ll u){
	if(vis[u]) return;
	vis[u]=1;
	for(auto v:g[u]){
		ll y=v.first,w=v.second;
		res[u]=(res[u]+(w==0)*dp[u][1]%mod)%mod;
		dp[u][w]++;
		dfs(y);
		ll tmp=((dp[y][0]*dp[u][1]%mod)+res[y])%mod;
		res[u]=(res[u]%mod+tmp)%mod;
		(dp[u][0]+=dp[y][0])%=mod;
		(dp[u][1]+=dp[y][1])%=mod;
	}
}
void solve(){
    cin>>n;
    for(ll i=1,s;i<=n;++i){
        cin>>s;
        for(ll j=1,v,w;j<=s;++j) cin>>v>>w,g[i].push_back({v,w});
    }
    dfs(1);
    cout<<res[1];
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}
