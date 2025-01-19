#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
typedef pair<ll,ll>PLL;
const ll inf=0x3f3f3f3f;
ll dx[]={0,-2,-2,-1,-1,1,1,2,2};
ll dy[]={0,-1,1,-2,2,-2,2,-1,1};
ll n,m,hn,hm,dp[30][30],vis[30][30];
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>hn>>hm;
    n+=2;m+=2;hn+=2;hm+=2;
    for(ll i=0;i<=8;++i) vis[hn+dx[i]][hm+dy[i]]=1;
    dp[2][2]=1;
    for(ll i=2;i<=n;++i)
        for(ll j=2;j<=m;++j){
            if(vis[i][j]) continue;
            dp[i][j]+=dp[i-1][j]+dp[i][j-1];
        }
    cout<<dp[n][m];
    return 0;
}