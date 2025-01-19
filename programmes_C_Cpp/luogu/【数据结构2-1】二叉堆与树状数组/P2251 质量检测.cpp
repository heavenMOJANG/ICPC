#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll n,m,st[1000010][21];
ll query(int l,ll r){
    ll k=log2(r-l+1);
    return min(st[l][k],st[r-(1<<k)+1][k]);
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;++i)    cin>>st[i][0];
    for(ll j=1;j<=21;++j)
        for(ll i=1;i+(1<<j)-1<=n;++i) st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
    for(ll i=1;i<=n-m+1;++i){
        ll l=i,r=i+m-1;
        cout<<query(l,r)<<"\n";
    }
    return 0;
}