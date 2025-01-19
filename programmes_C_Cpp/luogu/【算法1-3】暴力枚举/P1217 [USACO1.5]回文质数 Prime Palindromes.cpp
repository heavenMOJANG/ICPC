#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll a,b;
ll check(ll x){
    if(x==2) return 1;
    for(ll i=2;i<=sqrt(x);++i) if(x%i==0) return 0;
    return 1;
}
ll judge(ll x){
    ll res=0,tmp=x;
    while(x){
       res=res*10+x%10;
       x/=10;
    }
    return res==tmp;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>a>>b;
    for(ll i=a;i<=b;++i){
        if(i==9989900) break;
        if(judge(i)&&check(i)) cout<<i<<"\n";
    }
    return 0;
}