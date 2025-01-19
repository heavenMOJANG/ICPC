#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
typedef pair<ll,ll>PLL;
const ll inf=0x7f;
ll dx[]={-1,1,0,0};
ll dy[]={0,0,-1,1};
ll m,n,a[100010],dp[100010][22],LOG2[100010];
void st_init(){
    LOG2[0]=-1;
    for(ll i=1;i<=100000;++i) LOG2[i]=LOG2[i>>1]+1;
    for(ll i=1;i<=n;++i) dp[i][0]=a[i];
    ll p=log2(n);
    for(ll k=1;k<=p;++k)
        for(ll s=1;s+(1<<k)<=n+1;++s) dp[s][k]=min(dp[s][k-1],dp[s+(1<<(k-1))][k-1]);
}
ll st_query(ll l,ll r){
    ll k=LOG2[r-l+1];
    return min(dp[l][k],dp[r-(1<<k)+1][k]);
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;++i) cin>>a[i];
    st_init();
    for(ll i=1,a,b;i<=m;++i) cin>>a>>b,cout<<st_query(a,b)<<" ";
    return 0;
}