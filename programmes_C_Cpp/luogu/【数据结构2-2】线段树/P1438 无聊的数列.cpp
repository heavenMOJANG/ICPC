#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
struct Node{ll sum,tag;}t[400010];
ll n,m,a[100010];
void build(ll l,ll r,ll p){
    if(l==r) return;
    ll mid=l+r>>1;
    build(l,mid,p<<1);
    build(mid+1,r,p<<1|1);
    t[p].sum=t[p<<1].sum+t[p<<1|1].sum;
}
void pushDown(ll p,ll k){
    if(t[p].tag){
        t[p<<1].tag+=t[p].tag;
        t[p<<1|1].tag+=t[p].tag;
        t[p<<1].sum+=t[p].tag*(k-(k>>1));
        t[p<<1|1].sum+=t[p].tag*(k>>1);
        t[p].tag=0;
    }
}
void update(ll L,ll R,ll c,ll l,ll r,ll p){
    if(L<=l&&R>=r){
        t[p].tag+=c;
        t[p].sum+=c*(r-l+1);
        return;
    }
    pushDown(p,r-l+1);
    ll mid=l+r>>1;
    if(L<=mid) update(L,R,c,l,mid,p<<1);
    if(mid<R) update(L,R,c,mid+1,r,p<<1|1);
    t[p].sum=t[p<<1].sum+t[p<<1|1].sum;
}
ll query(ll L,ll R,ll l,ll r,ll p){
    if(L<=l&&R>=r) return t[p].sum;
    pushDown(p,r-l+1);
    ll mid=l+r>>1,res=0;
    if(L<=mid) res+=query(L,R,l,mid,p<<1);
    if(mid<R) res+=query(L,R,mid+1,r,p<<1|1);
    return res;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;++i) cin>>a[i];
    build(1,n,1);
    while(m--){
        ll opt;cin>>opt;
        if(opt==1){
            ll l,r,k,d;cin>>l>>r>>k>>d;
            update(l+1,r,d,1,n,1);
            update(l,l,k,1,n,1);
            update(r+1,r+1,-(k+d*(r-l)),1,n,1);
        }
        else{
            ll p;cin>>p;
            cout<<a[p]+query(1,p,1,n,1)<<"\n";
        }
    }
    return 0;
}