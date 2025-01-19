#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll n,f[1000010],s[1000010];
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    f[1]=1;f[2]=2;
    s[0]=1;s[1]=s[0]+f[1];
    s[2]=s[1]+f[2];
    for(ll i=3;i<=n;++i){
        f[i]=(f[i-1]+f[i-2]+2*(s[i-3]))%10000;
        s[i]=(s[i-1]+f[i])%10000;
    }
    cout<<f[n];
    return 0;
}