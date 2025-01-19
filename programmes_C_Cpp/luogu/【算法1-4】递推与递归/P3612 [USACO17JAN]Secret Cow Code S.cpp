#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll n,len,t;
string s;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>s>>n;len=t=s.size();
    while(len<n) len*=2;
    len/=2;
    while(t<n){
        if(n-len>1) n-=len+1;
        else if(n-len==1) n=len;
        len/=2;
    }
    cout<<s[n-1];
    return 0;
}