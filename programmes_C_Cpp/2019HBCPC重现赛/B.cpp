#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,n,q,p;
ll extend_gcd(ll a,ll b,ll&x,ll&y){
    if(!b){x=1;y=0;return a;}
    ll d=extend_gcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
ll mod_inverse(ll a,ll m){
    ll x,y;
    extend_gcd(a,m,x,y);
    return (x%m+m)%m;
}
ll fast_pow(ll a,ll x){
    ll res=1;
    a%=p;
    while(x){
        if(x&1) res=(res*a)%p;
        a=(a*a)%p;
        x>>=1;
    }
    return res;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>q>>n>>p;
        if(p==1){cout<<0<<"\n";continue;}
        if(q==1){cout<<n%p<<"\n";continue;}
        if(n==1){cout<<1%p<<"\n";continue;}
        ll f1=(fast_pow(q,n)-1)%p,f2=mod_inverse(q-1,p)*p;
        cout<<q%p*f1%p*f2%p<<"\n";
    }
    return 0;
}