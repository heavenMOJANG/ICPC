#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
constexpr ll mod=998244353;
ll n;
ll exgcd(ll a,ll b,ll&x,ll&y){
    if(b==0){x=1,y=0;return a;}
    ll d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
void solve(){
    cin>>n;
    if(n==1){cout<<"0\n";return;}
    if(n==2){cout<<"1\n";return;}
    ll a=1,b=mod,c=n-1;
    ll x,y,d=exgcd(a,b,x,y);
    x=-x*c;
    cout<<(x%mod+mod)%mod<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
