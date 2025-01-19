#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
constexpr ll N=4e5+10;
struct Edge{
    ll id,l,r;
    bool operator<(const Edge&x)const{return l<x.l;}
}e[2*N];
ll n,m,nn,nxt[N][20],res[N];
void init(){
    ll k=1;
    for(ll i=1;i<=nn;++i){
        while(k<=nn&&e[k].l<=e[i].r) k++;
        nxt[i][0]=k-1;
    }
    for(ll i=1;(1<<i)<=n;++i)
        for(ll s=1;s<=nn;++s) nxt[s][i]=nxt[nxt[s][i-1]][i-1];
}
void calc(ll x){
    ll len=e[x].l+m,cur=x,ans=1;
    for(ll i=log2(N);i>=0;--i){
        ll p=nxt[cur][i];
        if(p&&e[p].r<len) ans+=1<<i,cur=p;
    }
    res[e[x].id]=ans+1;
}
void solve(){
    cin>>n>>m;
    for(ll i=1;i<=n;++i){
        e[i].id=i;
        cin>>e[i].l>>e[i].r;
        if(e[i].r<e[i].l) e[i].r+=m;
    }
    sort(e+1,e+1+n);
    nn=n;
    for(ll i=1;i<=n;++i){
        nn++;
        e[nn]=e[i];
        e[nn].l=e[i].l+m;
        e[nn].r=e[i].r+m;
    }
    init();
    for(ll i=1;i<=n;++i) calc(i);
    for(ll i=1;i<=n;++i) cout<<res[i]<<" ";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}
