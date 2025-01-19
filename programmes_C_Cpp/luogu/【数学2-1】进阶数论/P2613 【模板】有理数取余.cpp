#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
constexpr ll mod=19260817;
ll a,b;
ll read(){
    string s;
    cin>>s;
    ll res=0;
    for(ll i=0;i<s.size();++i) res=(res*10+s[i]-'0')%mod;
    return res;
}
ll qpow(ll a,ll x){
    ll res=1;
    while(x){
        if(x&1) res=res*a%mod;
        a=a*a%mod;
        x>>=1;
    }
    return res;
}
void solve(){
    a=read();b=read();
    if(b==0){cout<<"Angry!";return;}
    cout<<a*qpow(b,mod-2)%mod;
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}
