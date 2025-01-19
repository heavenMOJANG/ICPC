#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
constexpr ll N=100010;
ll n,t[N];
ll lowbit(ll x){return x&(-x);}
void update(ll x,ll d){while(x<=n) t[x]+=d,x+=lowbit(x);}
ll sum(ll x){ll res=0;while(x) res+=t[x],x-=lowbit(x);return res;}
void solve(){
    while(cin>>n&&n){
        memset(t,0,sizeof(t));
        for(ll i=1,l,r;i<=n;++i) cin>>l>>r,update(l,1),update(r+1,-1);
        for(ll i=1;i<=n;++i) cout<<sum(i)<<(i==n?"\n":" ");
    }
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}