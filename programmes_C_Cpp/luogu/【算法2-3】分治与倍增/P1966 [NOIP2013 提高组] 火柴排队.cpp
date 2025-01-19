#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define lowbit(x) (x&(-x))
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
const ll mod=1e8-3;
struct Node{ll idx,val;}a[100010],b[100010],c[100010];
ll n,h[100010],ans;
void update(ll x){while(x<=n) h[x]++,x+=lowbit(x);}
ll getSum(ll x){
    ll res=0;
    while(x) res+=h[x],x-=lowbit(x);
    return res;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>a[i].val,a[i].idx=i;
    for(ll i=1;i<=n;++i) cin>>b[i].val,b[i].idx=i;
    sort(a+1,a+1+n,[](const Node&x,const Node&y){return x.val>y.val;});
    sort(b+1,b+1+n,[](const Node&x,const Node&y){return x.val>y.val;});
    for(ll i=1;i<=n;++i) c[a[i].idx].val=b[i].idx,c[i].idx=i;
    sort(c+1,c+1+n,[](const Node&x,const Node&y){return x.val>y.val;});
    for(ll i=1;i<=n;++i){
        ans=(ans+getSum(c[i].idx))%mod;
        update(c[i].idx);
    }
    cout<<ans;
    return 0;
}
