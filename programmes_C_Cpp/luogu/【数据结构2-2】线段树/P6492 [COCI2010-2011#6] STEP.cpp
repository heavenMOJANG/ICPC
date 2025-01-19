#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
struct Node{ll sum,pre,suf,l,r;}t[800010];
ll n,q;
void pushUp(ll l,ll r,ll p){
    t[p].l=t[p<<1].l;
    t[p].r=t[p<<1|1].r;
    if(t[p<<1].r!=t[p<<1|1].l) t[p].sum=max(max(t[p<<1].sum,t[p<<1|1].sum),t[p<<1].suf+t[p<<1|1].pre);
    else t[p].sum=max(t[p<<1].sum,t[p<<1|1].sum);
    ll mid=l+r>>1;
    if(t[p<<1].pre!=mid-l+1) t[p].pre=t[p<<1].pre;
    else
        if(t[p<<1].r==t[p<<1|1].l) t[p].pre=mid-l+1;
        else t[p].pre=mid-l+1+t[p<<1|1].pre;
    if(t[p<<1|1].suf!=r-mid) t[p].suf=t[p<<1|1].suf;
    else
        if(t[p<<1].r==t[p<<1|1].l) t[p].suf=r-mid;
        else t[p].suf=r-mid+t[p<<1].suf;
}
void build(ll l,ll r,ll p){
    if(l==r){
        t[p]={1,1,1,0,0};
        return;
    }
    ll mid=l+r>>1;
    build(l,mid,p<<1);
    build(mid+1,r,p<<1|1);
    pushUp(l,r,p);
}
void update(ll l,ll r,ll x,ll p){
    if(l==r){
        ll k=t[p].l^1;
        t[p].l=t[p].r=k;
        return;
    }
    ll mid=l+r>>1;
    if(x<=mid) update(l,mid,x,p<<1);
    else update(mid+1,r,x,p<<1|1);
    pushUp(l,r,p);
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    build(1,n,1);
    while(q--){
        ll x;cin>>x;
        update(1,n,x,1);
        cout<<t[1].sum<<"\n";
    }
    return 0;
}
