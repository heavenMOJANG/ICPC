#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
constexpr ll mod=1e9+7;
ll n,k,a[1000010]={1,1};
void solve(){
    cin>>n>>k;
    ll res=1,f[n+10]={1,1};
    for(ll i=1;i<n;++i)
        if(i<=k) f[i]=(f[i-1]*i)%mod;
        else f[i]=(f[i-1]*k)%mod;
    cout<<a[n]*f[n-1]%mod<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    for(ll i=1;i<=1000000;++i) a[i]=a[i-1]*i%mod;
    while(_--) solve();
    return 0;
}
