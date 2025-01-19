#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,ltd,cost;
ll query(ll l,ll r){
    ll res=0;
    cost+=(r-l)*(r-l);
    cout<<"? "<<l<<" "<<r<<endl;
    cout.flush();
    cin>>res;
    return res;
}
ll work(ll l,ll r){
    if(l==r) return l;
    ll mid=l+r>>1;
    ll x=work(l,mid),y=work(mid+1,r);
    ll inv_all=query(x,y),inv_r;
    if(x+1==y) inv_r=0;
    else inv_r=query(x+1,y);
    if(inv_r+y-x==inv_all) return x;
    else return y;
}
void solve(){
    cin>>n;
    ltd=5*n*n;
    cost=0;
    ll ans=work(1,n);
    cout<<"! "<<ans<<endl;
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}