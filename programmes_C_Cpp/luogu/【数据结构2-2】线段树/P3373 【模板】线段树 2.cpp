#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int inf=0x3f3f3f3f;
constexpr int N=1e5+10;
struct Node{int l,r,sum,add,mul;}t[N<<2];
int n,q,m,a[N];
void pushUp(int p){
    t[p].sum=(t[p<<1].sum+t[p<<1|1].sum)%m;
}
void build(int p,int pl,int pr){
    t[p]={pl,pr,0ll,0ll,1ll};
    if(pl==pr){t[p].sum=a[pl];return;}
    int mid=pl+pr>>1;
    build(p<<1,pl,mid);
    build(p<<1|1,mid+1,pr);
    pushUp(p);
}
void pushDown(int p){
    Node&rt=t[p],&l=t[p<<1],&r=t[p<<1|1];
    l.sum=(l.sum*rt.mul%m+(l.r-l.l+1)*rt.add%m)%m;
    r.sum=(r.sum*rt.mul%m+(r.r-r.l+1)*rt.add%m)%m;
    l.mul=l.mul*rt.mul%m,r.mul=r.mul*rt.mul%m;
    l.add=(l.add*rt.mul%m+rt.add)%m,r.add=(r.add*rt.mul%m+rt.add)%m;
    rt.add=0,rt.mul=1;
}
void modifyAdd(int p,int L,int R,int k){
    if(L<=t[p].l&&t[p].r<=R){
        t[p].sum=(t[p].sum+k*(t[p].r-t[p].l+1)%m)%m;
        t[p].add=(t[p].add+k)%m;
        return;
    }
    pushDown(p);
    int mid=t[p].l+t[p].r>>1;
    if(L<=mid) modifyAdd(p<<1,L,R,k);
    if(R>mid) modifyAdd(p<<1|1,L,R,k);
    pushUp(p);
}
void modifyMul(int p,int L,int R,int k){
    if(L<=t[p].l&&t[p].r<=R){
        t[p].sum=t[p].sum*k%m;
        t[p].add=t[p].add*k%m;
        t[p].mul=t[p].mul*k%m;
        return;
    }
    pushDown(p);
    int mid=t[p].l+t[p].r>>1;
    if(L<=mid) modifyMul(p<<1,L,R,k);
    if(R>mid) modifyMul(p<<1|1,L,R,k);
    pushUp(p);
}
int query(int p,int L,int R){
    if(L<=t[p].l&&t[p].r<=R) return t[p].sum;
    pushDown(p);
    int mid=t[p].l+t[p].r>>1,res=0ll;
    if(L<=mid) res=(res+query(p<<1,L,R))%m;
    if(R>mid) res=(res+query(p<<1|1,L,R))%m;
    return res;
}
void solve(){
    cin>>n>>q>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    build(1,1,n);
    for(int i=1,op,x,y,k;i<=q;++i){
        cin>>op>>x>>y;
        switch(op){
            case 1:cin>>k;modifyMul(1,x,y,k);break;
            case 2:cin>>k;modifyAdd(1,x,y,k);break;
            case 3:cout<<query(1,x,y)<<"\n";break; 
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}