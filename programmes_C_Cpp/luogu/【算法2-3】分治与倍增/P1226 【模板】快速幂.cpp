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
ll a,b,p;
ll pow(ll a,ll b,ll p){
    ll res=1%p;
    while(b){
        if(b&1) res=res*a%p;
        b>>=1;a=a*a%p;
    }
    return res;
}
int main(int argc,const char*arv[]){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>a>>b>>p;
    cout<<a<<"^"<<b<<" mod "<<p<<"="<<pow(a,b,p);
    return 0;
}