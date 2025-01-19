#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
constexpr ll mod=998244353;
constexpr ll N=2000;
ll n,s[N+10],t[N+10],fac[2*N+10],inv[2*N+10],res;
ll qpow(ll a,ll x){
    ll res=1;
    while(x){
        if(x&1) res=res*a%mod;
        a=a*a%mod;
        x>>=1;
    }
    return res;
}
void init(){
    fac[0] = 1;
    for(ll i=1;i<=2*N;++i) fac[i]=fac[i-1]*i%mod;
    inv[2*N]=qpow(fac[2*N],mod-2);
    for(ll i=2*N-1;i>=0;--i) inv[i]=inv[i+1]*(i+1)%mod;
}
ll C(ll n,ll m){return fac[n]*inv[m]%mod*inv[n-m]%mod;}
ll calc(ll x,ll y){
    if(x>y) swap(x,y);
    if(!x) return 1;
    return C(x+y,x);
}
void solve(){
    init();
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>s[i];
    for(ll i=1;i<=n;++i) cin>>t[i];
    sort(s+1,s+1+n);
    sort(t+1,t+1+n);
    for(ll i=1;i<=n;++i)
        for(ll j=1;j<=n;++j) (res+=abs(s[i]-t[j])*calc(i-1,j-1)%mod*calc(n-i,n-j)%mod)%=mod;
    cout<<res;
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}