#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll a,b,c,gcd1,gcd2,lcm1,lcm2;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    scanf("%lld%lld%lld",&a,&b,&c);
    gcd1=__gcd(a,b);
    lcm1=a*b/gcd1;
    gcd2=__gcd(lcm1,c);
    lcm2=lcm1*c/gcd2;
    printf("%lld",lcm2);
    return 0;
}
