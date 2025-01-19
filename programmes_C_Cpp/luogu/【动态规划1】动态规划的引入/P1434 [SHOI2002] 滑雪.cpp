#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
constexpr ll dx[]={-1,0,1,0};
constexpr ll dy[]={0,-1,0,1};
ll r,c,dp[110][110],g[110][110],maxn;
ll check(ll x,ll y){
    if(x==0||y==0||x==r+1||y==c+1) return 0;
    return 1;
}
ll dfs(ll x,ll y){
    if(dp[x][y]) return dp[x][y];
    ll res=0;
    for(ll i=0;i<4;++i){
        ll tx=x+dx[i],ty=y+dy[i];
        if(check(tx,ty)&&g[x][y]<g[tx][ty]) res=max(res,dfs(tx,ty));
    }
    return dp[x][y]=res+1;
}
void solve(){
    cin>>r>>c;
    for(ll i=1;i<=r;++i)
        for(ll j=1;j<=c;++j) cin>>g[i][j];
    for(ll i=1;i<=r;++i)
        for(ll j=1;j<=c;++j) maxn=max(maxn,dfs(i,j));
    cout<<maxn;
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}
