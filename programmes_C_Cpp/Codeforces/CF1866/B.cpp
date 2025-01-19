#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
constexpr ll mod=998244353;
ll n,m,flag,cnt;
map<ll,ll>na,nb;
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
    cin>>n;
    vector<ll>fx(n+10);
    for(ll i=1;i<=n;++i) cin>>fx[i];
    for(ll i=1,x;i<=n;++i) cin>>x,na[fx[i]]=x;
    cin>>m;
    vector<ll>fy(m+10);
    for(ll i=1;i<=m;++i) cin>>fy[i];
    for(ll i=1,x;i<=m;++i){
        cin>>x,nb[fy[i]]=x;
        na[fy[i]]-=nb[fy[i]];
        if(na[fy[i]]<0) flag=1;
    }
    if(flag){cout<<"0";return;}
    for(auto it=na.begin();it!=na.end();++it) cnt+=(it->second>0);
    cout<<qpow(2,cnt);
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}
