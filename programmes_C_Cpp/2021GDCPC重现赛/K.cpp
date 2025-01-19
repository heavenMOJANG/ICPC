#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
typedef pair<ll,ll>PLL;
const ll inf=0x3f3f3f3f;
ll dx[]={-1,1,0,0};
ll dy[]={0,0,-1,1};
ll n,m,minn[3010][3010],maxn[3010][3010];
ll lowbit(ll x){return x&(-x);}
void update(ll l,ll r,ll val){
    ll pl=3010-l;
    while(pl<3010){
        ll pr=r;
        while(pr<3010){
            minn[pl][pr]=min(minn[pl][pr],val);
            maxn[pl][pr]=max(maxn[pl][pr],val);
            pr+=lowbit(pr);
        }
        pl+=lowbit(pl);
    }
}
ll query(ll l,ll r){
    ll rmax=0,rmin=inf,pl=3010-l;
    while(pl){
        ll pr=r;
        while(pr){
            rmax=max(rmax,maxn[pl][pr]);
            rmin=min(rmin,minn[pl][pr]);
            pr-=lowbit(pr);
        }
        pl-=lowbit(pl);
    }
    if(rmin==inf) return 0;
    else return rmax-rmin;

}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(minn,0x3f,sizeof(minn));
    cin>>n>>m;
    for(ll i=1,l,r,val;i<=n;++i) cin>>l>>r>>val,update(l,r,val);
    ll ans=0;
    while(m--){
        ll op,a,b;cin>>op>>a>>b;
        ll l=a^ans,r=b^ans;
        if(op==1){
            ll val;cin>>val;
            update(l,r,val);
        }
        else{
            ans=query(l,r);
            cout<<ans<<"\n";
        }
    }
    return 0;
}