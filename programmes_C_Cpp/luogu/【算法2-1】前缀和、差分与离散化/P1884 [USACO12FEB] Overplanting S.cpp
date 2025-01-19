#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
struct Node{ll x,y1,y2,z;}e[10010];
struct segmentTree{ll cnt,sum;}t[40010];
ll n,a[10010],row[10010],idx;
ll cmp(Node x,Node y){return x.x==y.x?x.y1<y.y1:x.x<y.x;}
void pushUp(ll p){t[p].sum=t[p<<1].sum+t[p<<1|1].sum;}
void update(ll p,ll l,ll r,ll qL,ll qR,ll d){
    if(qL<=l&&r<=qR){
        t[p].cnt+=d;
        if(t[p].cnt) t[p].sum=row[r+1]-row[l];
        else pushUp(p);
        return;
    }
    ll mid=l+r>>1;
    if(qL<=mid) update(p<<1,l,mid,qL,qR,d);
    if(qR>mid) update(p<<1|1,mid+1,r,qL,qR,d);
    if(t[p].cnt) t[p].sum=row[r+1]-row[l];
    else pushUp(p);
}
void solve(){
    cin>>n;
    for(ll i=1;i<=n;++i){
        ll x1,y1,x2,y2;
        cin>>x1>>y2>>x2>>y1;
        ll k1=2*i-1,k2=2*i;
        e[k1]={x1,y1,y2,1};
        e[k2]={x2,y1,y2,-1};
        a[++idx]=y1;a[++idx]=y2;
    }
    sort(a+1,a+1+idx);
    ll len=unique(a+1,a+1+idx)-a-1;
    n<<=1;
    for(ll i=1;i<=n;i+=2){
        ll p1=lower_bound(a+1,a+1+len,e[i].y1)-a;
        ll p2=lower_bound(a+1,a+1+len,e[i].y2)-a;
        row[p1]=e[i].y1;row[p2]=e[i].y2;
        e[i].y1=e[i+1].y1=p1;
        e[i].y2=e[i+1].y2=p2;
    }
    sort(e+1,e+1+n,cmp);
    ll res=0;
    for(ll i=1;i<=n;++i){
        update(1,1,n,e[i].y1,e[i].y2-1,e[i].z);
        res+=t[1].sum*(e[i+1].x-e[i].x);
    }
    cout<<res;
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}