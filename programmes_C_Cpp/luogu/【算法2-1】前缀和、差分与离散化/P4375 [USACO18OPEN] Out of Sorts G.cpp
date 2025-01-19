#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,res,a[100010],b[100010],c[100010],t[100010];
ll lowbit(ll x){return x&(-x);}
void update(ll x){while(x<=n) t[x]++,x+=lowbit(x);}
ll query(ll x){ll res=0;while(x) res+=t[x],x-=lowbit(x);return res;}
void solve(){
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>a[i],b[i]=a[i];
    sort(b+1,b+1+n);
    res=1;
    for(ll i=1;i<=n;++i){
        ll t=lower_bound(b+1,b+n+1,a[i])-b;
        update(t);
        c[i]=query(i);
        res=max(res,i-c[i]);
    }
    cout<<res;
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}