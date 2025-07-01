#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
constexpr ll mod=998244353;
ll n,m,k;
ll qpow(ll a,ll x){
    ll res=1;
    a%=mod;
    while(x){
        if(x&1) res=res*a%mod;
        a=a*a%mod;
        x>>=1;
    }
    return res;
}
void solve(){
    cin>>n>>m>>k;
    if(n==k) cout<<m<<"\n";
    else cout<<qpow(m,n-k)<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _;cin>>_;
    while(_--) solve();
    return 0;
}