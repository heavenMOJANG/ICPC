#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
void solve(){
    ll n,q;cin>>n;
    vector<ll>a(n+1);
    vector<vector<ll>>f(n+1,vector<ll>(30));
    for(ll i=1;i<=n;++i) cin>>a[i],f[i][0]=a[i];
    for(ll k=1;k<=20;++k)
        for(ll i=1;i+(1<<k)-1<=n;++i) f[i][k]=f[i][k-1]&f[i+(1<<(k-1))][k-1];
    auto query=[&](ll l,ll r)->ll
    {
        ll k=log2(r-l+1);
        return f[l][k]&f[r-(1<<k)+1][k];
    };
    cin>>q;
    vector<ll>res(q);
    for(ll i=0,L,k;i<q;++i){
        cin>>L>>k;
        ll l=L,r=n,p=-1;
        while(l<=r){
            ll mid=l+r>>1;
            if(query(L,mid)>=k) p=mid,l=mid+1;
            else r=mid-1;
        }
        res[i]=p;
    }
    for(ll i=0;i<q;++i) cout<<res[i]<<" \n"[i==q-1];
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
