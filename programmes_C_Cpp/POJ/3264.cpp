#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,q,a[200010],dpmax[200010][20],dpmin[200010][20];
void init(){
    for(ll i=1;i<=n;++i) dpmax[i][0]=dpmin[i][0]=a[i];
    ll k=log2(n);
    for(ll j=1;j<=k;++j)
        for(ll i=1;i<=n-(1<<j)+1;++i){
            dpmax[i][j]=max(dpmax[i][j-1],dpmax[i+(1<<(j-1))][j-1]);
            dpmin[i][j]=min(dpmin[i][j-1],dpmin[i+(1<<(j-1))][j-1]);
        }
}
ll query(ll l,ll r){
    ll k=log2(r-l+1);
    return max(dpmax[l][k],dpmax[r-(1<<k)+1][k])-min(dpmin[l][k],dpmin[r-(1<<k)+1][k]);
}
void solve(){
    cin>>n>>q;
    for(ll i=1;i<=n;++i) cin>>a[i];
    init();
    while(q--){
        ll l,r;cin>>l>>r;
        cout<<query(l,r)<<"\n";
    }
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}
