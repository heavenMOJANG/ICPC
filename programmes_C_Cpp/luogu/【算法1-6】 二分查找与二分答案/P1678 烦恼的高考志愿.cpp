#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll n,m,a[100010],b[100010],res;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>m>>n;
    for(ll i=1;i<=m;++i) cin>>a[i];
    for(ll i=1;i<=n;++i) cin>>b[i];
    sort(a+1,a+1+m);
    for(ll i=1;i<=n;++i){
        ll l=0,r=m;
        while(l<r){
            ll mid =l+r>>1;
            if(b[i]>=a[mid]) l=mid+1;
            else r=mid;
        }
        if(b[i]<=a[1]) res+=a[1] - b[i];
        else res+=min(abs(a[l-1]-b[i]),abs(a[l]-b[i]));
    }
    cout<<res;
    return 0;
}