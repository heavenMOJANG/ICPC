#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
struct Node{double sum,add;}t[4000010];
ll n,m,k,ans;
void pushUp(ll p){t[p].sum=t[ls].sum+t[rs].sum;}
void pushDown(ll l,ll r,ll p){
    ll d=r-l+1;
    if(t[p].add){
        t[ls].sum+=t[p].add*(d-(d>>1));
        t[rs].sum+=t[p].add*(d>>1);
        t[ls].add+=t[p].add;
        t[rs].add+=t[p].add;
        t[p].add=0;
    }
}
void build(ll l,ll r,ll p){
    t[p].add=0;
    if(l==r){
        t[p].sum=0;
        return;
    }
    ll mid=(l+r)>>1;
    build(l,mid,ls);
    build(mid+1,r,rs);
    pushUp(p);
}
void update(ll L,ll R,double c,ll l,ll r,ll p){
    if(L<=l&&r<=R){
        t[p].add+=c;
        t[p].sum+=c*(r-l+1);
        return;
    }
    pushDown(l,r,p);
    ll mid=(l+r)>>1;
    if(L<=mid) update(L,R,c,l,mid,ls);
    if(mid<R) update(L,R,c,mid+1,r,rs);
    pushUp(p);
}
void decrease(ll L,ll R,ll l,ll r,ll p){
    if(l==r){
        if(t[p].sum>=1) t[p].sum-=1,ans++;
        return;
    }
    pushDown(l,r,p);
    ll mid=(l+r)>>1;
    if(L<=mid) decrease(L,R,l,mid,ls);
    if(mid<R) decrease(L,R,mid+1,r,rs);
    pushUp(p);
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    build(1,n,1);
    while(m--){
        ll op,l,r;cin>>op>>l>>r;
        if(op==1){
            double x;cin>>x;
            update(l,r,x/k,1,n,1);
        }
        else decrease(l,r,1,n,1);
    }
    cout<<ans;
    return 0;
}