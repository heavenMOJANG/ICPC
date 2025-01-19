#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,a[30],dp[30],g[30][30],path[30];
void print(ll x){
    if(path[x]) print(path[x]);
    cout<<x<<" ";
}
void solve(){
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>a[i];
    for(ll i=1;i<n;++i)
        for(ll j=i+1;j<=n;++j) cin>>g[i][j];
    for(ll i=1;i<=n;++i){
	    dp[i]=a[i]; 
	    for(ll j=i-1;j>0;--j){
			if(g[j][i]&&dp[i]<dp[j]+a[i]){
				dp[i]=dp[j]+a[i];
				path[i]=j;
			}
		}
	}
	ll maxn=-1,pos=0;
    for(ll i=1;i<=n;++i)
	    if(maxn<dp[i]) pos=i,maxn=dp[i];
    print(pos);
    cout<<"\n"<<maxn;
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}
