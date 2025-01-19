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
ll n,k,a[100010],l,r;
ll check(ll x){
    ll res=0;
    for(ll i=1;i<=n;++i) res+=a[i]/x;
    return res>=k;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(ll i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+1+n);
    r=a[n]+1;
    while(l<r){
        ll mid=(l+r)>>1;
        if(mid==0) break;
        if(check(mid)) l=mid+1;
        else r=mid;
    }
    cout<<r-1;
    return 0;
}