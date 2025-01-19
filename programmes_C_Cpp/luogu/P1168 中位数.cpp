#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll n,a[100010],b[100010],t[400010];
void update(ll u,ll l,ll r,ll k){
    if(l==r) t[u]++;
    else{
        ll mid=(l+r)>>1;
        if(k<=mid) update(u<<1,l,mid,k);
        else update(u<<1|1,mid+1,r,k);
        t[u]=t[u<<1]+t[u<<1|1];
    }
}
ll query(ll u,ll l,ll r,ll k){
    if(l==r) return l;
    ll mid=(l+r)>>1;
    if(k<=t[u<<1]) return query(u<<1,l,mid,k);
    return query(u<<1|1,mid+1,r,k-t[u<<1]);
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++) cin>>a[i],b[i]=a[i];
    sort(a+1,a+1+n);
    ll cnt=unique(a+1,a+1+n)-a-1;
    for(ll i=1;i<=n;i++) b[i]=lower_bound(a+1,a+1+cnt,b[i])-a;
    for(ll i=1;i<=n;i++){
        update(1,1,n,b[i]);
        if(i&1){
            ll k=query(1,1,n,(i+1)/2);
            cout<<a[k]<<"\n";
        }
    }
    return 0;
}