#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll res,x,y,t;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>x>>y;
    t=x*y;
    for(ll i=x;i<=y;++i){
        if(t%i!=0) continue;
        if(__gcd(i,t/i)!=x) continue;
        res++;
    }
    cout<<res;
    return 0;
}
