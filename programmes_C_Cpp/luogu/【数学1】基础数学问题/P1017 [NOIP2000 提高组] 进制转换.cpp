#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll n,b;
void trans(ll n,ll b){
    if(n==0) return;
    ll m=n%b;
    if(m<0) m-=b,n+=b;
    if(m>=10) m+='A'-10;
    else m+='0';
    trans(n/b,b);
    printf("%c",m);
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    scanf("%lld%lld",&n,&b);
    printf("%lld=",n);
    trans(n,b);
    printf("(base%lld)",b);
    return 0;
}
