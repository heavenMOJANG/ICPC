#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,x,y;
void solve(){
    cin>>n>>x>>y;
    ll a=n/x,b=n/y;
    ll c=n/(lcm(x,y));
    a-=c,b-=c;
    ll res=0;
    res+=(n+n-a+1)*a/2;
    res-=(1+b)*b/2;
    cout<<res<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
