#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
struct Node{ll l,r,tag,clr;}t[400010];
ll L,T,O,sum;
void pushUp(ll p){t[p].clr=t[p<<1].clr|t[p<<1|1].clr;}
void build(ll l,ll r,ll p){
    t[p].l=l,t[p].r=r,t[p].tag=0;
    if(l==r){
        t[p].clr=1;
        return;
    }
    ll mid=l+r>>1;
    build(l,mid,p<<1);
    build(mid+1,r,p<<1|1);
    pushUp(p);
}
void pushDown(ll p){
	if(t[p].tag){
		t[p<<1].tag=t[p<<1|1].tag=t[p].tag;
		t[p<<1].clr=t[p<<1|1].clr=t[p].clr;
		t[p].tag=0;
		return;
	}
}
void update(ll L,ll R,ll d,ll p){
	if(t[p].l>=L&&t[p].r<=R){
		t[p].clr=d;
		t[p].tag=1;
		return;
	}
	pushDown(p);
	ll mid=t[p].l+t[p].r>>1;
	if(L<=mid) update(L,R,d,p<<1);
	if(R>mid) update(L,R,d,p<<1|1);
	pushUp(p);
}
void query(ll L,ll R,ll p){
	if(L<=t[p].l&&t[p].r<=R){
		sum|=t[p].clr;
		return;
	}
	pushDown(p);
	ll mid=t[p].l+t[p].r>>1;
	if(L<=mid) query(L,R,p<<1);
	if(mid<R) query(L,R,p<<1|1);
}
ll cal(ll x){
	ll res=0;
	while(x){
		if(x&1) res++;
		x>>=1;
	}
	return res;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>L>>T>>O;
    build(1,L,1);
    while(O--){
        char ch;cin>>ch;
        if(ch=='C'){
            ll a,b,c;cin>>a>>b>>c;
            c=1<<(c-1);
            if(a>b) swap(a,b);
            update(a,b,c,1);
        }
        else{
            ll a,b;cin>>a>>b;
            if(a>b) swap(a,b);
            sum=0;
            query(a,b,1);
            cout<<cal(sum)<<"\n";
        }
    }
    return 0;
}
