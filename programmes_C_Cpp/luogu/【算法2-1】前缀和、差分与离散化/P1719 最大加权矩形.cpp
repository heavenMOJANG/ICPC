#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll n,g[130][130],res=LLONG_MIN;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;++i)
        for(ll j=1;j<=n;++j) cin>>g[i][j];
    for(ll i=1;i<=n;++i){
        ll t[128];
        memset(t,0,sizeof(t));
        for(ll j=i;j<=n;++j){
            for(ll k=1;k<=n;++k) t[k]+=g[j][k];
            ll dp=0;
            for(ll k=1;k<=n;++k){
                dp=(dp>0?dp+t[k]:t[k]);
                res=max(res,dp);
            }
        }
    }
    cout<<res;
    return 0;
}