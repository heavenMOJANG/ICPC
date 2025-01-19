#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
typedef pair<ll,ll>PLL;
const ll inf=0x7f;
ll dx[]={-1,1,0,0};
ll dy[]={0,0,-1,1};
ll a,b,p=19260817,ans;
ll extend_gcd(ll a,ll b,ll&x,ll&y){
    if(!b){x=1;y=0;return a;}
    ll d=extend_gcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
ll mod_inverse(ll a){
    ll x,y;
    extend_gcd(a,p,x,y);
    return (x%p+p)%p;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>a>>b;
    a%=p;b=mod_inverse(b);
    ans=a*b%p;
    if(!ans) cout<<"Angry!";
    else cout<<ans;
    return 0;
}