#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int N=500010;
struct Node{int val,tag;}t[N<<2];
int n,q,a[N],b[N],c[N],d[N],s[N],res;
void pushUp(int p){t[p].val=max(t[p<<1].val,t[p<<1|1].val);}
void build(int pl,int pr,int p){
    if(pl==pr){
        t[p].val=s[pl];
        return;
    }
    int mid=pl+pr>>1;
    build(pl,mid,p<<1);
    build(mid+1,pr,p<<1|1);
    pushUp(p);
}
void pushDown(int p){
    if(t[p].tag){
        t[p<<1].tag+=t[p].tag;
        t[p<<1|1].tag+=t[p].tag;
        t[p<<1].val+=t[p].tag;
        t[p<<1|1].val+=t[p].tag;
        t[p].tag=0;
    }
}
void update(int pl,int pr,int p,int L,int R,int k){
    if(L<=pl&&pr<=R){
        t[p].val+=k;
        t[p].tag+=k;
        return;
    }
    pushDown(p);
    int mid=pl+pr>>1;
    if(L<=mid) update(pl,mid,p<<1,L,R,k);
    if(R>mid) update(mid+1,pr,p<<1|1,L,R,k);
    pushUp(p);
}
void solve(){
    cin>>n>>q;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i) cin>>b[i];
    for(int i=1;i<n;++i) cin>>c[i];
    for(int i=n;i>=1;--i){
        d[i]=a[i]-b[i];
        s[i]=s[i+1]+d[i];
        res+=a[i];
    }
    build(1,n,1);
    while(q--){
        int p,x,y,z;cin>>p>>x>>y>>z;
        res-=a[p];
        update(1,n,1,1,p,-d[p]);
        a[p]=x;
        b[p]=y;
        d[p]=x-y;
        res+=a[p];
        update(1,n,1,1,p,d[p]);
        cout<<res-max(0ll,t[1].val)<<"\n";
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
