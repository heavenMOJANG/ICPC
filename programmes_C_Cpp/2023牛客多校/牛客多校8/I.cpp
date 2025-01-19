#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
constexpr ll mod=998244353;
ll m;
string s,t;
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
    cin>>m>>s>>t;
    if(s.size()==t.size()){
        if(s==t) for(ll i=1;i<=m;++i) cout<<qpow(26,i)<<" ";
        else for(ll i=1;i<=m;++i) cout<<"0 ";
    }

    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}
