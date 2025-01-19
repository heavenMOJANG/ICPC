#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,a[100010],t[100010],sum;
ll lowbit(ll x){return x&(-x);}
void update(ll x,ll d){while(x<=n) t[x]+=d,x+=lowbit(x);}
ll calc(ll x){ll res=0;while(x) res+=t[x],x-=lowbit(x);return res;}
void solve(){
    cin>>n;
    sum=0;
    fill(t+1,t+1+n,0);
    for(ll i=1;i<=n;++i) cin>>a[i],update(a[i],1),sum+=i-calc(a[i]);
    if(n==1){cout<<"0 1\n";return;}
    ll minn=(sum&1?2:0),maxn=0,tmp=n;
    while(tmp) maxn++,tmp>>=1;
    maxn=(1LL<<maxn)-1;
    cout<<minn<<" "<<max(1ll,minn^maxn^2)<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}