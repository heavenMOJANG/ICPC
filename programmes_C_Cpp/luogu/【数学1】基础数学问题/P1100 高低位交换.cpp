#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll n,res;
string s;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    while(n){
        s=char('0'+n%2)+s;
        n>>=1;
    }
    while(s.size()!=32) s="0"+s;
    for(ll i=0;i<16;++i) res+=(s[i]-'0')*pow(2,16-i-1);
    for(ll i=16;i<32;++i) res+=(s[i]-'0')*pow(2,48-i-1);
    cout<<res;
    return 0;
}
