#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
void solve(){
    ll n;cin>>n;
    vector<ll>a(n),b(n);
    ll suma=0,sumb=0,mina=1e9,minb=1e9;
    for(ll i=0;i<n;++i) cin>>a[i],suma+=a[i],mina=min(mina,a[i]);
    for(ll i=0;i<n;++i) cin>>b[i],sumb+=b[i],minb=min(minb,b[i]);
    cout<<min(suma+n*minb,sumb+n*mina)<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
