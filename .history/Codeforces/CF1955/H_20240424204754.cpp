#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
int dp[2][1<<10+10];
char s[60][60];
void solve(){
    int n,m,k;cin>>n>>m>>k;
	int op = 0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j) cin>>s[i][j];
	for(int i=0;i<(1ll<<10);++i) dp[0][i] = 0;
	for(int x=1,u,v,w;x<=k;x++){
		op^=1;
		cin>>u>>v>>w;
		vector<int> cnt(13);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j){
				if(s[i][j]!='#') continue;
				int dis=ceil(sqrt((u-i)*(u-i)+(v-j)*(v-j)));
				if(dis<=10) cnt[dis]++;
			}
		for(int i=1;i<=10;i++) cnt[i] += cnt[i-1];
		for(int i=0;i<bits(10);i++){
			dp[op][i] = dp[op^1][i];
			ll res = 3;
			for(int j=1;j<=10;j++){
				if(i & bits(j-1)){
					dp[op][i] = max(dp[op][i],dp[op^1][i - bits(j-1)] - res + cnt[j]*w);
				}
				res*=3ll;
			}
		}
	}
	ll ans = 0;
	for(int i=0;i<bits(10);i++) ans = max(ans,dp[op][i]);
	cout<<ans<<endl;
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}