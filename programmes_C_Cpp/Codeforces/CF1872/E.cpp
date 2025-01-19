#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
struct Node{ll s0,s1,tag;}t[400010];
ll n,a[100010],q;
string s;
void pushUp(ll p){
    t[p].s0=t[p<<1].s0^t[p<<1|1].s0;
    t[p].s1=t[p<<1].s1^t[p<<1|1].s1;
}
void pushDown(ll p){
    if(t[p].tag){
        swap(t[p<<1].s0,t[p<<1].s1);
        swap(t[p<<1|1].s0,t[p<<1|1].s1);
        t[p<<1].tag^=t[p].tag,
        t[p<<1|1].tag^=t[p].tag, 
        t[p].tag=0;
    }
}
void build(ll p,ll l,ll r){
    if(l==r){
        if(s[l]=='0') t[p]={a[l],0,0};
        else t[p]={0,a[l],0};
        return;
    }
    t[p].tag=0;
    ll mid=l+r>>1;
    build(p<<1,l,mid), 
    build(p<<1|1,mid+1,r);
    pushUp(p);
}
void update(ll p,ll L,ll R,ll pl,ll pr){
    if(L<=pl&&pr<=R){
        swap(t[p].s0,t[p].s1);
        t[p].tag^=1;
        return ;
    }
    ll mid=pl+pr>>1;
    pushDown(p);
    if(L<=mid) update(p<<1,L,R,pl,mid);
    if(R>mid) update(p<<1|1,L,R,mid+1,pr);
    pushUp(p);
}
ll query(ll p,ll L,ll R,ll pl,ll pr,ll d){
    if(L<=pl&&pr<=R) return d==0ll?t[p].s0:t[p].s1;
    ll mid=pl+pr>>1;
    pushDown(p);
    ll res=0;
    if(L<=mid) res^=query(p<<1,L,R,pl,mid,d);
    if(R>mid) res^=query(p<<1|1,L,R,mid+1,pr,d);
    return res;
}
void solve(){
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>a[i];
    cin>>s;s=" "+s;
    build(1,1,n);
    cin>>q;
    while(q--){
        ll op;cin>>op;
        switch(op){
            case 1:{
                ll x,y;cin>>x>>y;
                update(1,x,y,1,n);
            }break;
            case 2:{
                ll d;cin>>d;
                cout<<query(1,1,n,1,n,d)<<" ";
            }break;
        }
    }
    cout<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
