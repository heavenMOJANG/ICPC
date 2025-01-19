#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,k,a[3010],b[3010];
void solve(){
    cin>>n>>k;
    for(ll i=1;i<=n;++i) cin>>a[i];
    for(ll i=1;i<=n;++i) cin>>b[i];
    vector maxn(2,vector(2,vector(n+1,LLONG_MIN)));
    vector dp(n+1,vector(k+1,0ll));
    for(ll i=1;i<=n;++i)
		for(ll j=1;j<=min(i,k);++j){
			for(ll x=0;x<=1;++x)
				for(ll y=0;y<=1;++y)
					maxn[x][y][i-j]=max(maxn[x][y][i-j],dp[i-1][j-1]+(x==0?a[i]:-a[i])+(y==0?b[i]:-b[i]));
            for(ll x=0;x<=1;++x)
				for(ll y=0;y<=1;++y)
					dp[i][j]=max({dp[i][j],dp[i-1][j],dp[i][j],maxn[x][y][i-j]+(x==0?-b[i]:b[i])+(y==0?-a[i]:a[i])});
        }
    cout<<dp[n][k]<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
