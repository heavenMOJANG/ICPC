#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
constexpr ll N=32010;
struct{ll v,p,q;}a[N];
ll n,m,dp[70][N];
void dfs(ll u,ll c){
    if(c<=0) return;
    for(ll i=1;i<=m;++i)
        if(a[i].q==u){
            for(ll j=0;j<=c-a[i].v;++j) dp[i][j]=dp[u][j]+a[i].p*a[i].v;
            dfs(i,c-a[i].v);
            for(ll j=a[i].v;j<=c;++j) dp[u][j]=max(dp[u][j],dp[i][j-a[i].v]);
        }
        else continue;
    return;
}
void solve(){
    cin>>n>>m;
    for(ll i=1;i<=m;++i) cin>>a[i].v>>a[i].p>>a[i].q;
    dfs(0,n);
    cout<<dp[0][n];
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}
