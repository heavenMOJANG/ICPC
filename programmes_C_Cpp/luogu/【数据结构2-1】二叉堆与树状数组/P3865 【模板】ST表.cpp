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
ll n,m,a[100010],dp_max[100010][22],LOG2[100010];
void ST_init(){
    LOG2[0]=-1;
    for(ll i=1;i<=100000;++i) LOG2[i]=LOG2[i>>1]+1;
    for(ll i=1;i<=n;++i) dp_max[i][0]=a[i];
    ll p=log2(n);
    for(ll k=1;k<=p;++k)
        for(ll s=1;s+(1<<k)<=n+1;++s) dp_max[s][k]=max(dp_max[s][k-1],dp_max[s+(1<<(k-1))][k-1]);
}
ll ST_query(ll l,ll r){
    ll k=LOG2[r-l+1];
    return max(dp_max[l][k],dp_max[r-(1<<k)+1][k]);
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;++i) cin>>a[i];
    ST_init();
    for(ll i=1;i<=m;++i){
        ll l,r;cin>>l>>r;
        cout<<ST_query(l,r)<<"\n";
    }
    return 0;
}