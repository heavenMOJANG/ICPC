#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,p[64],flag;
void modify(ll x){
    for(ll i=63;i>=0;--i)
        if(x>>i==1)
            if(p[i]==0){p[i]=x;return;}
        else x^=p[i];
    flag=1;
}
ll calc(){
    ll res=0;
    for(ll i=63;i>=0;--i) res=max(res,res^p[i]);
    return res;
}
void solve(){
    cin>>n;
    for(ll i=1,x;i<=n;++i) cin>>x,modify(x);
    cout<<calc(); 
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}