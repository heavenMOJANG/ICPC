#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
void solve(){
    ll n,m;cin>>n>>m;
    if(n%m==0){cout<<"0\n";return;}
    ll g=gcd(n,m),up=(n%m)/g,down=m/g;
    ll tmp=down;
    while(tmp%2==0) tmp/=2;
    if(tmp!=1){cout<<"-1\n";return;}
    vector<ll>num(30);
    for(ll i=29;i>=0;--i) if((1ll<<i)&up) num[i]=m;
    ll ans=0;
    for(ll i=0;i<30&&(1<<i)<down;++i) ans+=num[i]/2,num[i+1]+=num[i]/2;
    cout<<ans<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
