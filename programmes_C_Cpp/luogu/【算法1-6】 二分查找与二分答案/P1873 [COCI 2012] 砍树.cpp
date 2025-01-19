#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll n,m,a[1000010],l,r=1e9;
ll check(ll x){
    ll res=0;
    for(ll i=1;i<=n;++i) if(a[i]>x) res+=a[i]-x;
    return res>=m;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;++i) cin>>a[i];
    while(l<r){
        ll mid=(l+r)>>1;
        if(check(mid)) l=mid+1;
        else r=mid;
    }
    cout<<l-1;
    return 0;
}