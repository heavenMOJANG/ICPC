#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
void solve(){
    ll n,m;cin>>n>>m;
    vector<ll>a(n),b(m),fa(30),fb(30);
    for(ll i=0;i<n;++i){
        cin>>a[i];
        ll cnt=0,tmp=a[i];
        while(tmp) fa[cnt++]+=tmp%2,tmp>>=1;
    }
    for(ll i=0;i<m;++i){
        cin>>b[i];
        ll cnt=0,tmp=b[i];
        while(tmp) fb[cnt++]+=tmp%2,tmp>>=1;
    }
    ll minn=0,maxn=0;
    if(n&1){
        ll tmp=1;
        for(ll i=0;i<30;++i){
            if(fb[i]) maxn+=tmp;
            else if(fa[i]&1) maxn+=tmp;
            if(fa[i]&1)minn+=tmp;
            tmp<<=1;
        }
    }
    else{
        ll tmp=1;
        for(ll i=0;i<30;++i){
            if(fb[i]) minn+=0;
            else if(fa[i]&1) minn+=tmp;
            if(fa[i]&1) maxn+=tmp;
            tmp<<=1;
        }
    }
    cout<<minn<<" "<<maxn<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
