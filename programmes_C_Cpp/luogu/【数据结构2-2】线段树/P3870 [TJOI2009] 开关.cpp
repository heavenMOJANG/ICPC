#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
struct Node{ll l,r,sum0,sum1,tag;}t[4000010];
ll n,m,c,a,b;
void build(ll l,ll r,ll p){
    t[p]={l,r,r-l+1,0,0};
    if(l==r) return;
    ll mid=l+r>>1;
    build(l,mid,p<<1);
    build(mid+1,r,p<<1|1);
}
void pushDown(ll p){
    swap(t[p<<1].sum0,t[p<<1].sum1);
    swap(t[p<<1|1].sum0,t[p<<1|1].sum1);
    t[p].tag^=1;
    t[p<<1].tag^=1;
    t[p<<1|1].tag^=1;
}
void update(ll l,ll r,ll p){
    if(t[p].l>r||t[p].r<l) return;
    if(t[p].l>=l&&t[p].r<=r){
        t[p].tag^=1,swap(t[p].sum0,t[p].sum1);
        return;
    }
    if(t[p].tag) pushDown(p);
    update(l,r,p<<1);
    update(l,r,p<<1|1);
    t[p].sum0=t[p<<1].sum0+t[p<<1|1].sum0;
    t[p].sum1=t[p<<1].sum1+t[p<<1|1].sum1;
}
ll query(ll l,ll r,ll p){
	if(t[p].l>r||t[p].r<l) return 0;
    if(t[p].l>=l&&t[p].r<=r) return t[p].sum1;
    if(t[p].tag) pushDown(p);
    return query(l,r,p<<1)+query(l,r,p<<1|1);
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    build(1,n,1);
    while(m--){
        cin>>c>>a>>b;
        if(c) cout<<query(a,b,1)<<"\n";
        else update(a,b,1);
    }
    return 0;
}