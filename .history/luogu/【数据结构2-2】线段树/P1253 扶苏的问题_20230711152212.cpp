#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=LLONG_MIN;
struct Node{ll maxn,add,mdfy=inf;}t[4000010];
ll n,q,a[1000010];
void build(ll l,ll r,ll p){
    if(l==r){
        t[p].maxn=a[l];
        return;
    }
    ll mid=l+r>>1;
    build(l,mid,p<<1);
    build(mid+1,r,p<<1|1);
    t[p].maxn=max(t[p<<1].maxn,t[p<<1|1].maxn);
}
void pushDown(ll p){
    if(t[p].mdfy!=inf){
		t[p<<1].maxn=t[p<<1|1].maxn=t[p<<1].mdfy=t[p<<1|1].mdfy=t[p].mdfy;
		t[p<<1].add=t[p<<1|1].add=0;
		t[p].mdfy=inf;
	}
	if(t[p].add){
		t[p<<1].add+=t[p].add;
		t[p<<1|1].add+=t[p].add;
		t[p<<1].maxn+=t[p].add;
		t[p<<1|1].maxn+=t[p].add;
		t[p].add=0;
	}
}
void updateAdd(ll L,ll R,ll d,ll l,ll r,ll p){
	if(L<=l&&r<=R){
		t[p].maxn+=d;
		t[p].add+=d;
		return;
	}
	pushDown(p);
    ll mid=l+r>>1;
	if(mid>=L) updateAdd(L,R,d,l,mid,p<<1);
	if(mid<R) updateAdd(L,R,d,mid+1,r,p<<1|1);
	t[p].maxn=max(t[p<<1].maxn,t[p<<1|1].maxn);
}

void updateModify(ll L,ll R,ll d,ll l,ll r,ll p){
	if(L<=l&&r<=R){
		t[p].maxn=d;
		t[p].mdfy=d;
		t[p].add=0;
		return;
	}
	pushDown(p);
    ll mid=l+r>>1;
	if(mid>=L) updateModify(L,R,d,l,mid,p<<1);
    if(mid<R) updateModify(L,R,d,mid+1,r,p<<1|1);
	t[p].maxn=max(t[p<<1].maxn,t[p<<1|1].maxn);
}

ll query(ll L,ll R,ll l,ll r,ll p){
	if(L<=l&&r<=R) return t[p].maxn;
	pushDown(p);
	ll mid=l+r>>1,res=inf;
	if(mid>=L) res=max(res,query(L,R,l,mid,p<<1));
    if(mid<R) res=max(res,query(L,R,mid+1,r,p<<1|1));
	return res;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(ll i=1;i<=n;++i) cin>>a[i];
    build(1,n,1);
    while(q--){
        ll op,l,r;cin>>op>>l>>r;
        switch(op){
            case 1:{
                ll x;cin>>x;
                updateModify(l,r,x,1,n,1);
                break;
            }
            case 2:{
                ll x;cin>>x;
                updateAdd(l,r,x,1,n,1);
                break;
            }
            case 3:{
                cout<<query(l,r,1,n,1)<<"\n";
                break;
            }
        }
    }
    return 0;
}
