#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
struct Segment{
    ll l,r,h,val;
    bool operator<(const Segment&x)const{return h<x.h;}
}s[800010];
struct Node{ll l,r,sum,len;}t[1600010];
ll n,a[800010],res;
void pushUp(ll p){
    if(t[p].sum) t[p].len=a[t[p].r+1]-a[t[p].l];
    else t[p].len=t[p<<1].len+t[p<<1|1].len;
}
void build(ll p,ll pl,ll pr){
    t[p]={pl,pr,0,0};
    if(pl==pr) return;
    ll mid=pl+pr>>1;
    build(p<<1,pl,mid);
    build(p<<1|1,mid+1,pr);
}
void update(ll p,ll L,ll R,ll val){
    if(a[t[p].r+1]<=L||R<=a[t[p].l]) return;
    if(L<=a[t[p].l]&&a[t[p].r+1]<=R){
        t[p].sum+=val;
        pushUp(p);
        return;
    }
    update(p<<1,L,R,val);
    update(p<<1|1,L,R,val);
    pushUp(p);
}
void solve(){
    cin>>n;
    for(ll i=1;i<=n;++i){
        ll x1,x2,y1,y2;cin>>x1>>y1>>x2>>y2;
        a[2*i-1]=x1,a[2*i]=x2;
        s[2*i-1]={x1,x2,y1,1};
        s[2*i]={x1,x2,y2,-1};
    }
    n<<=1;
    sort(s+1,s+1+n);
    sort(a+1,a+1+n);
    ll cnt=unique(a+1,a+1+n)-a-1;
    build(1,1,cnt-1);
    for(ll i=1;i<n;++i){
        update(1,s[i].l,s[i].r,s[i].val);
        res+=t[1].len*(s[i+1].h-s[i].h);
    } 
    cout<<res;
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}
