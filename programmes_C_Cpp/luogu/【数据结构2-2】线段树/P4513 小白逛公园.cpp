#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
struct Node{ll sum,lmax,rmax,maxn;}t[2000010];
ll n,m,a[500010];
void pushup(ll p){
    t[p].sum=t[p<<1].sum+t[p<<1|1].sum;
    t[p].lmax=max(t[p<<1].lmax,t[p<<1].sum+t[p<<1|1].lmax);
    t[p].rmax=max(t[p<<1|1].rmax,t[p<<1|1].sum+t[p<<1].rmax);
    t[p].maxn=max(max(t[p<<1].maxn,t[p<<1|1].maxn),t[p<<1].rmax+t[p<<1|1].lmax);
    return;
}
void build(ll l,ll r,ll p){
    if(l==r){
        t[p].sum=t[p].lmax=t[p].rmax=t[p].maxn=a[l];
        return;
    }
    ll mid=l+r>>1;
    build(l,mid,p<<1);
    build(mid+1,r,p<<1|1);
    pushup(p);
}
void update(ll pos,ll c,ll l,ll r,ll p){
    if(l==r){
        t[p].sum=t[p].lmax=t[p].rmax=t[p].maxn=c;
        return;
    }
    ll mid=l+r>>1;
    if(pos<=mid) update(pos,c,l,mid,p<<1);
    if(mid<pos) update(pos,c,mid+1,r,p<<1|1);
    pushup(p);
}
Node query(ll L,ll R,ll l,ll r,ll p){
    if(L<=l&&r<=R) return t[p];
    ll mid=l+r>>1;
    Node left,right;
    ll jl=0,jr=0;
    if(L<=mid) left=query(L,R,l,mid,p<<1),jl=1;
    if(mid<R) right=query(L,R,mid+1,r,p<<1|1),jr=1;
    if(jl&jr){
        Node res;
        res.sum=left.sum+right.sum;
        res.lmax=max(left.lmax,left.sum+right.lmax);
        res.rmax=max(right.rmax,right.sum+left.rmax);
        res.maxn=max(max(left.maxn,right.maxn),left.rmax+right.lmax);
        return res;
    }
    if(jl) return left;
    if(jr) return right;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;++i) cin>>a[i];
    build(1,n,1);
    while(m--){
        ll k;cin>>k;
        if(k==1){
            ll a,b;cin>>a>>b;
            if(a>b) swap(a,b);
            cout<<query(a,b,1,n,1).maxn<<"\n";
        }
        else{
            ll p,s;cin>>p>>s;
            update(p,s,1,n,1);
        }
    }
    return 0;
}