#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll L,k,n,a[10000010];
ll check(ll x){
    ll res=0;
    for(ll i=2;i<=n;++i){
        res+=(a[i]-a[i-1])/x;
        if((a[i]-a[i-1])%x==0) res--;
        if(res>k) return 0;
    }
    return 1;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>L>>n>>k;
	for(ll i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+1+n);
    ll l=1,r=L;
    while(l<=r){
        ll mid=(l+r)>>1;
        if(check(mid)) r=mid-1;
        else l=mid+1;
    }
	cout<<l;
    return 0;
}