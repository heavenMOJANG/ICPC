#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll N=200010;
struct Node{ll l,r,sum;}t[N<<5];
ll n,m,cnt,root[N],a[N],b[N];
ll build(ll l,ll r){
    ll p=++cnt;
    t[p].sum=0;
    ll mid=l+r>>1;
    if(l<r){
        t[p].l=build(l,mid);
        t[p].r=build(mid+1,r);
    }
    return p;
}
ll update(ll pre,ll l,ll r,ll x) {
    ll p=++cnt;
    t[p].l=t[pre].l;
    t[p].r=t[pre].r;
    t[p].sum=t[pre].sum+1;
    ll mid=l+r>>1;
    if(l<r){
        if(x<=mid) t[p].l=update(t[pre].l,l,mid,x);
        else t[p].r=update(t[pre].r,mid+1,r,x);
    }
    return p;
}
ll query(ll u,ll v,ll l,ll r,ll k) {
    if(l==r) return l;
    ll x=t[t[v].l].sum-t[t[u].l].sum;
    ll mid=l+r>>1;
    if(k<=x) return query(t[u].l,t[v].l,l,mid,k);
    else return query(t[u].r,t[v].r,mid+1,r,k-x);
}
void solve(){
    cin>>n>>m;
    for(ll i=1;i<=n;++i) cin>>a[i],b[i]=a[i];
    sort(b+1,b+1+n);
    ll tot=unique(b+1,b+n+1)-b-1;
    root[0]=build(1,tot);
    for(ll i=1;i<=n;++i) {
        ll x=lower_bound(b+1,b+tot+1,a[i])-b;
        root[i]=update(root[i-1],1,tot,x);
    }
    for(ll i=1,l,r,k;i<=m;++i){
        cin>>l>>r>>k;
        ll x=query(root[l-1],root[r],1,tot,k);
        cout<<b[x]<<"\n";
    }
}
int main(int argc,const char*argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}
