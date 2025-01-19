#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll L,n,m,a[50010];
ll check(ll x){
    ll res=0,cur=0;
    for(ll i=1;i<=n+1;++i)
        if(a[i]-a[cur]<x) res++;
        else cur=i;
    return res<=m;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>L>>n>>m;
    for(ll i=1;i<=n;++i) cin>>a[i];
    a[n+1]=L;
    ll l=0,r=L;
    while(l<=r){
        ll mid=l+r>>1;
        if(check(mid)) l=mid+1;
        else r=mid-1;
    }
    cout<<l-1;
    return 0;
}