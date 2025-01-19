#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) (x&(-x))
typedef long long ll;
constexpr ll inf=0x7fffffff;
ll n,tree[500010],r[500010];
struct Node{
    ll num,val;
    bool operator<(const Node&x)const{return val==x.val?num<x.num:val<x.val;}
}a[500010];
void update(ll x,ll d){while(x<=n) tree[x]+=d,x+=lowbit(x);}
ll sum(ll x){ll res=0;while(x) res+=tree[x],x-=lowbit(x);return res;}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>a[i].val,a[i].num=i;
    sort(a+1,a+1+n);
    for(ll i=1;i<=n;++i) r[a[i].num]=i;
    ll res=0;
    for(ll i=n;i;--i) update(r[i],1),res+=sum(r[i]-1);
    cout<<res;
    return 0;
}