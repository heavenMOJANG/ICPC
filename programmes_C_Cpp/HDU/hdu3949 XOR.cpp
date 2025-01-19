#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,q,a[10010],flag,idx;
void gauss(){
    ll i,k=1;
    for(ll j=1ll<<62;j;j>>=1){
        for(i=k;i<=n;++i) if(a[i]&j) break;
        if(i>n) continue;
        swap(a[i],a[k]);
        for(i=1;i<=n;++i) if(i!=k&&a[i]&j) a[i]^=a[k];
        k++;
    }
    k--;
    flag=(k!=n?1:0);
    n=k;
}
ll query(ll k){
    ll res=0;
    if(flag) k--;
    if(!k) return 0;
    for(ll i=n;i;--i){
        if(k&1) res^=a[i];
        k>>=1;
    }
    if(k) return -1;
    return res;
}
void solve(){
    cout<<"Case #"<<++idx<<":\n";
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>a[i];
    gauss();
    cin>>q;
    for(ll i=1,k;i<=q;++i) cin>>k,cout<<query(k)<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}