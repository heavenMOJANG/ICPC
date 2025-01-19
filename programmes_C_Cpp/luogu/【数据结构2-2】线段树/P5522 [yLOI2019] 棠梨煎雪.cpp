#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll inf=0x3f3f3f3f;
ll n,m,q,check[100010],val[100010],ans;
struct Node{ll l,r,k,val,f;}t[400010];
string s;
void pushUp(ll p){
	t[p].k=t[ls].k|t[rs].k;
	t[p].val=t[ls].val|t[rs].val;
	if((t[ls].k&t[rs].k)&(t[ls].val^t[rs].val)) t[p].f=0;
	else
        if((!t[ls].f)||(!t[rs].f)) t[p].f=0;
	    else t[p].f=1;
}
void build(ll l,ll r,ll p){
	t[p].l=l,t[p].r=r;
	if(l==r){
		t[p].k=check[l];
		t[p].val=val[l];
		t[p].f=1;
		return;
	}
	ll mid=l+r>>1;
	build(l,mid,ls);
	build(mid+1,r,rs);
	pushUp(p);
}
void update(ll pos,ll k,ll val,ll p){
	if(t[p].l==t[p].r){
		t[p].k=k;
		t[p].val=val;
		t[p].f=1;
		return;
	}
	ll mid=t[p].l+t[p].r>>1;
	if(pos<=mid) update(pos,k,val,ls);
	else update(pos,k,val,rs);
	pushUp(p);
}
Node query(ll L,ll R,ll p){
	Node res;
	if(L<=t[p].l&&t[p].r<=R) return t[p];
	ll mid=t[p].l+t[p].r>>1;
	if(L<=mid&&mid<R){
		Node l=query(L,R,ls);
		Node r=query(L,R,rs);
		res.k=l.k|r.k;
		res.val=l.val|r.val;
		if((l.k&r.k)&(l.val^r.val)) res.f=0;
		else
            if((!l.f)||(!r.f)) res.f=0;
		    else res.f=1;
		return res;
	}
	if(L<=mid) return query(L,R,ls);
	if(mid<R) return query(L,R,rs);
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>q;
    for(ll i=1;i<=m;++i){
		cin>>s;s=" "+s;
		ll k=0,value=0;
		for(ll j=1;j<=n;++j){
			k<<=1;value<<=1;
			if(s[j]>='0'&&s[j]<='9') k|=1,value|=s[j]-'0';
			else k|=0,value|=0;
		}
		check[i]=k;
		val[i]=value;
	}
    build(1,m,1);
    while(q--){
        ll opt;cin>>opt;
        if(opt){
            ll pos;cin>>pos;
			cin>>s;s=" "+s;
			ll k=0,value=0;
			for(ll i=1;i<=n;++i){
				k<<=1;value<<=1;
				if(s[i]>='0'&&s[i]<='9') k|=1,value|=s[i]-'0';
				else k|=0,value|=0;
			}
			update(pos,k,value,1);
        }
        else{
            ll l,r,p=1;cin>>l>>r;
            Node x=query(l,r,1);
			if(!x.f){
				ans^=0;
				continue;
			}
			for(int i=1;i<=n;i++){
				if(!(x.k&1)) p<<=1;
				x.k>>=1;
			}
			ans^=p;
        }
    }
    cout<<ans;
    return 0;
}