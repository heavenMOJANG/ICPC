#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
typedef pair<ll,ll>PLL;
const ll inf=0x3f3f3f3f;
ll dx[]={-1,1,0,0};
ll dy[]={0,0,-1,1};
ll t,m,dp[1010];
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t>>m;
    for(ll i=1,c,w;i<=m;++i){
        cin>>c>>w;
        for(ll j=t;j>=c;--j) dp[j]=max(dp[j],dp[j-c]+w);
    }
    cout<<dp[t];
    return 0;
}