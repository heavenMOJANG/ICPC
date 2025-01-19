#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
using namespace std;
typedef long long ll;
struct Node{ll l,r,llen[2],rlen[2],mlen[2],sum,clr,fil,rev;}t[400010];
ll n,m,a[100010];
void up(ll p,ll k){
    t[p].llen[k]=(t[ls].llen[k]==t[ls].r-t[ls].l+1)?t[ls].llen[k]+t[rs].llen[k]:t[ls].llen[k];
    t[p].rlen[k]=(t[rs].rlen[k]==t[rs].r-t[rs].l+1)?t[rs].rlen[k]+t[ls].rlen[k]:t[rs].rlen[k];
    t[p].mlen[k]=max(t[ls].rlen[k]+t[rs].llen[k],max(t[ls].mlen[k],t[rs].mlen[k]));
}
void pushUp(ll p){
    up(p,0);
    up(p,1);
    t[p].sum=t[ls].sum+t[rs].sum;
}
void pushUpFill(ll p,ll k){t[p].llen[k]=t[p].rlen[k]=t[p].mlen[k]=t[p].r-t[p].l+1;}
void pushUpClear(ll p,ll k){t[p].llen[k]=t[p].rlen[k]=t[p].mlen[k]=0;}
void pushUpReverse(ll p){
    swap(t[p].llen[0],t[p].llen[1]);
    swap(t[p].rlen[0],t[p].rlen[1]);
    swap(t[p].mlen[0],t[p].mlen[1]);
    t[p].sum=t[p].r-t[p].l+1-t[p].sum;
    t[p].rev^=1;
    if(t[p].fil||t[p].clr) swap(t[p].fil,t[p].clr);
}
void pushDown(ll p){
    if(t[p].rev){
        pushUpReverse(ls),pushUpReverse(rs);
        t[p].rev=0;
    }
    if(t[p].clr){
        pushUpClear(ls,1),pushUpFill(ls,0);
        pushUpClear(rs,1),pushUpFill(rs,0);
        t[ls].clr=1,t[ls].fil=t[ls].rev=0;
        t[rs].clr=1,t[rs].fil=t[rs].rev=0;
        t[ls].sum=t[rs].sum=0;
        t[p].clr=0;
    }
    if(t[p].fil){
        pushUpClear(ls,0),pushUpFill(ls,1);
        pushUpClear(rs,0),pushUpFill(rs,1);
        t[ls].fil=1,t[ls].clr=t[ls].rev=0;
        t[rs].fil=1,t[rs].clr=t[rs].rev=0;
        t[ls].sum=t[ls].r-t[ls].l+1;
        t[rs].sum=t[rs].r-t[rs].l+1;
        t[p].fil=0;
    }
}
void build(ll l,ll r,ll p){
    t[p].l=l,t[p].r=r;
    if(l==r){
        t[p].llen[a[l]]=t[p].rlen[a[l]]=t[p].mlen[a[l]]=1;
        t[p].sum=a[l];
        return;
    }
    ll mid=l+r>>1;
    build(l,mid,ls);
    build(mid+1,r,rs);
    pushUp(p);
}
void updateFill(ll l,ll r,ll p){
    if(l<=t[p].l&&t[p].r<=r){
        t[p].llen[0]=t[p].rlen[0]=t[p].mlen[0]=0;
        t[p].llen[1]=t[p].rlen[1]=t[p].mlen[1]=t[p].sum=t[p].r-t[p].l+1;
        t[p].fil=1,t[p].clr=t[p].rev=0;
        return;
    }
    pushDown(p);
    ll mid=t[p].l+t[p].r>>1;
    if(l<=mid) updateFill(l,r,ls);
    if(mid<r) updateFill(l,r,rs);
    pushUp(p);
}
void updateClear(ll l,ll r,ll p){
    if(l<=t[p].l&&t[p].r<=r){
        t[p].llen[1]=t[p].rlen[1]=t[p].mlen[1]=t[p].sum=0;
        t[p].llen[0]=t[p].rlen[0]=t[p].mlen[0]=t[p].r-t[p].l+1;
        t[p].clr=1,t[p].fil=t[p].rev=0;
        return;
    }
    pushDown(p);
    ll mid=t[p].l+t[p].r>>1;
    if(l<=mid) updateClear(l,r,ls);
    if(mid<r) updateClear(l,r,rs);
    pushUp(p);
}
void updateReverse(ll p,ll l,ll r){
    if(l<=t[p].l&&t[p].r<=r){
        pushUpReverse(p);
        return;
    }
    pushDown(p);
    ll mid=t[p].l+t[p].r>>1;
    if(l<=mid) updateReverse(l,r,ls);
    if(mid<r) updateReverse(l,r,rs);
    pushUp(p);
}
ll querySum(ll l,ll r,ll p){
    if(l<=t[p].l&&t[p].r<=r) return t[p].sum;
    pushDown(p);
    ll mid=t[p].l+t[p].r>>1,res=0;
    if(l<=mid) res=querySum(l,r,ls);
    if(mid<r) res+=querySum(l,r,rs);
    return res;
}
ll queryLen(ll l,ll r,ll p){
    if(l<=t[p].l&&t[p].r<=r) return t[p].mlen[1];
    pushDown(p);
    ll mid=t[p].l+t[p].r>>1,res=min(t[rs].l+t[rs].llen[1]-1,r)-max(t[ls].r-t[ls].rlen[1]+1,l)+1;
    if(l<=mid) res=max(res,queryLen(l,r,ls));
    if(mid<r) res=max(res,queryLen(l,r,rs));
    return res;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;++i) cin>>a[i];
    build(1,n,1);
    while(m--){
        ll opt,l,r;cin>>opt>>l>>r;
        l++,r++;
        switch(opt){
            case 0:updateClear(l,r,1);break;
            case 1:updateFill(l,r,1);break;
            case 2:updateReverse(l,r,1);break;
            case 3:cout<<querySum(l,r,1)<<"\n";break;
            case 4:cout<<queryLen(l,r,1)<<"\n";break;
        }
    }
    return 0;
}
