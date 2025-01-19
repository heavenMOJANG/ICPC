#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll x,y,m,n,l;
ll exgcd(ll a,ll b,ll&x,ll&y){
    if(b==0){x=1,y=0;return a;}
    ll d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
void solve(){
    cin>>x>>y>>m>>n>>l;
    ll a=n-m,c=x-y;
    if(a<0) a=-a,c=-c;
    ll d=exgcd(a,l,x,y);
    if(c%d) cout<<"Impossible";
    else cout<<((x*(c/d))%(l/d)+(l/d))%(l/d);
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}
