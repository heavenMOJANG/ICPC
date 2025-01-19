#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
constexpr ll N=200010;
ll n,m,s,l,r,w[N],v[N],le[N],ri[N],p[N],q[N],res=LLONG_MAX;
void solve(){
    cin>>n>>m>>s;
    for(ll i=1;i<=n;++i) cin>>w[i]>>v[i],r=max(r,w[i]);
    for(ll i=1;i<=m;++i) cin>>le[i]>>ri[i];
    while(l<r){
        ll mid=(l+r+1)>>1;
        for(ll i=1;i<=n;++i){
            if(w[i]>mid) q[i]=q[i-1]+1,p[i]=p[i-1]+v[i];
            else  q[i]=q[i-1],p[i]=p[i-1];
        }
        ll x=0;
        for(ll i=1;i<=m;++i) x+=(q[ri[i]]-q[le[i]-1])*(p[ri[i]]-p[le[i]-1]);
        ll t=s-x;
        if(t<0) l=mid;
        else if(!t){cout<<0;return;}
        else r=mid-1;
        res=min(res,abs(t));
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