#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=0x3f3f3f3f;
const int N=1e5+10;
struct segmentTree{int sum,add;}t[N<<2];
int n,m,a[N];
void pushUp(int p){t[p].sum=t[p<<1].sum+t[p<<1|1].sum;}
void build(int p,int pl,int pr){
    t[p].add=0;
    if(pl==pr){t[p].sum=a[pl];return;}
    int mid=pl+pr>>1;
    build(p<<1,pl,mid);
    build(p<<1|1,mid+1,pr);
    pushUp(p);
}
void addTag(int p,int pl,int pr,int d){
    t[p].add+=d;
    t[p].sum+=d*(pr-pl+1);
}
void pushDown(int p,int pl,int pr){
    if(t[p].add){
        int mid=pl+pr>>1;
        addTag(p<<1,pl,mid,t[p].add);
        addTag(p<<1|1,mid+1,pr,t[p].add);
        t[p].add=0;
    }
}
void update(int p,int pl,int pr,int L,int R,int d){
    if(L<=pl&&pr<=R){addTag(p,pl,pr,d);return;}
    pushDown(p,pl,pr);
    int mid=pl+pr>>1;
    if(L<=mid) update(p<<1,pl,mid,L,R,d);
    if(R>mid) update(p<<1|1,mid+1,pr,L,R,d);
    pushUp(p);
}
int query(int p,int pl,int pr,int L,int R){
    if(L<=pl&&pr<=R) return t[p].sum;
    pushDown(p,pl,pr);
    int res=0,mid=pl+pr>>1;
    if(L<=mid) res+=query(p<<1,pl,mid,L,R);
    if(R>mid) res+=query(p<<1|1,mid+1,pr,L,R);
    return res;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    build(1,1,n);
    for(int i=1,op,l,r,d;i<=m;++i){
        cin>>op;
        switch(op){
            case 1:cin>>l>>r>>d;update(1,1,n,l,r,d);break;
            case 2:cin>>l>>r;cout<<query(1,1,n,l,r)<<"\n";break;
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}