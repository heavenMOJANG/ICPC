#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll t,n,k;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        ll res=0;
        cin>>n>>k;
        for(ll i=1;i<=n/2;++i) if(ceil((i*1.0)/(k*1.0))>res) res++;
        if(n&1&&ceil(((n/2+1)*1.0)/(k*1.0))>res) cout<<res*2+1<<"\n";
        else cout<<res*2<<"\n";
    }
    return 0;
}
