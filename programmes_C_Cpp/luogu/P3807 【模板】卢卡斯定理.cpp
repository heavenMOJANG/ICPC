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
ll T,fac[100010];
ll binary_exp(ll a,ll n,ll m){
    ll res=1;
    a%=m;
    while(n){
        if(n&1) res=(res*a)%m;
        a=(a*a)%m;
        n>>=1;
    }
    return res;
}
ll inverse(ll a,ll m){return binary_exp(fac[a],m-2,m);}
ll C(ll n,ll r,ll m){
    if(r>n) return 0;
    return ((fac[n]*inverse(r,m))%m*inverse(n-r,m)%m);
}
ll Lucas(ll n,ll r,ll m){
    if(r==0) return 1;
    return C(n%m,r%m,m)*Lucas(n/m,r/m,m)%m;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        ll a,b,m;cin>>a>>b>>m;
        fac[0]=1;
        for(ll i=1;i<=m;++i) fac[i]=(fac[i-1]*i)%m;
        cout<<Lucas(a+b,a,m)<<"\n";
    }
    return 0;
}