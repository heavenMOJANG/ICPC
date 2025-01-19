#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll n,a[200010],b[200010];
ld p;
ll check(ld x){
    ld res=0;
    ld maxp=p*x;
    for(ll i=1;i<=n;++i)
        if(b[i]-a[i]*x>=0) continue;
        else res+=fabs(a[i]*x-b[i]);
    return res<=maxp;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>p;        
    ld sum=0;
    for(ll i=1;i<=n;++i) cin>>a[i]>>b[i],sum+=a[i];
    if(sum<=p) return puts("-1.000000\n"),0;
    ld l=0,r=1e10;
    while(r-l>1e-6){
        ld mid=(l+r)/2;
        if(check(mid)) l=mid;
        else r=mid;    
    }
    cout<<fixed<<setprecision(10)<<l;
    return 0;
}