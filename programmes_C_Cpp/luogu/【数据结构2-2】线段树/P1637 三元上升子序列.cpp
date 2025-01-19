#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll n,a[30010],b[30010],c[30010],f[30010],ans;
ll lowbit(ll x){return x&(-x);}
void update(ll x){while(x<=n) c[x]++,x+=lowbit(x);}
ll sum(ll x){ll res=0;while(x) res+=c[x],x-=lowbit(x);return res;}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>a[i],b[i]=a[i];
    sort(b+1,b+1+n);
    ll len=unique(b+1,b+1+n)-b-1;
    for(ll i=1;i<=n;++i) a[i]=lower_bound(b+1,b+1+len,a[i])-b;
    for(ll i=1;i<=n;++i){
        if(a[i]>1) f[i]=sum(a[i]-1);
        update(a[i]);
    }
    memset(c,0,sizeof(c));
    for(ll i=n;i>=1;--i){
        if(a[i]<n) ans+=(sum(n)-sum(a[i]))*f[i];
        update(a[i]);
    }
    cout<<ans;
    return 0;
}
