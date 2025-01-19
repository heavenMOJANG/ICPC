#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
constexpr ll N=1000010;
ll n,m,p[1000010],d[1000010],s[1000010],t[1000010],a[1000010];
ll check(ll x){
    fill(a+1,a+1+n,0);
    ll res=0;
    for(ll i=1;i<=x;++i){
        a[s[i]]+=d[i];
        a[t[i]+1]-=d[i];
    }
    for(ll i=1;i<=n;++i){
        res+=a[i];
        if(res>p[i]) return 0;
    }
    return 1;
}
void solve(){
    cin>>n>>m;
    for(ll i=1;i<=n;++i) cin>>p[i];
    for(ll i=1;i<=m;++i) cin>>d[i]>>s[i]>>t[i];
    ll l=0,r=m+1;
    while(l+1<r){
        ll mid=l+r>>1;
        if(check(mid)) l=mid;
        else r=mid;
    }
    if(l==m) cout<<0;
    else cout<<"-1\n"<<l+1;
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}