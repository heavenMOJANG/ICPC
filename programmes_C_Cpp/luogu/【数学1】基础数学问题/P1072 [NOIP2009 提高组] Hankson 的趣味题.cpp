#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll T,a0,a1,b0,b1;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>a0>>a1>>b0>>b1;
        ll p=a0/a1,q=b1/b0,ans=0;
        for(ll x=1;x*x<=b1;++x) 
            if(b1%x==0){ 
                if(x%a1==0&&__gcd(x/a1,p)==1&&__gcd(q,b1/x)==1) ans++;
                ll y=b1/x; 
                if(x==y) continue; 
                if(y%a1==0&&__gcd(y/a1,p)==1&&__gcd(q,b1/y)==1) ans++;
            }
        cout<<ans<<"\n";
    }
    return 0;
}
