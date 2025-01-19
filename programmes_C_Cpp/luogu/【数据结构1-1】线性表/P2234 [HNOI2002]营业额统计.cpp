#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100010;
ll n,a[N],b[N],pre[N],nxt[N];
ll cmp(const ll &x,const ll &y){return a[x]<a[y];}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;++i) cin>>a[i],b[i]=i;
    sort(b+1,b+1+n,cmp);
    pre[b[1]]=-1,nxt[b[n]]=n+1;
    for(ll i=2;i<=n;++i) pre[b[i]]=b[i-1];
    for(ll i=1;i<n;++i) nxt[b[i]]=b[i+1];
    ll res=a[1];
    for(ll i=n,tmp;i>=2;--i){
        if(pre[i]==-1) tmp=abs(a[i]-a[nxt[i]]);
        else if(nxt[i]==n+1) tmp=abs(a[i]-a[pre[i]]);
        else tmp=min(abs(a[i]-a[nxt[i]]),abs(a[i]-a[pre[i]]));
        res+=tmp;
        pre[nxt[i]]=pre[i];nxt[pre[i]]=nxt[i];
    }
    cout<<res;
    return 0;
}