#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
struct Node{ll l,r,h;}a[10010];
ll n,m,l,r,h,len,w[10010],b[10010],hgt[510];
void modify(ll l,ll r,ll h){
    ll L=b[l],R=b[r];
    if(L==R) for(ll i=l;i<=r;++i) w[i]=max(w[i],h);
    else{
        ll i=l,j=r;
        while(b[i]==L) w[i]=max(w[i],h),i++;
        while(b[j]==R) w[j]=max(w[j],h),j--;
        for(ll k=b[i];k<=b[j];++k) hgt[k]=max(hgt[k],h);
    }
}
void solve(){
    while(cin>>l>>h>>r){
        a[++m]={l,r-1,h};
        n=max(n,r);
    }
    len=sqrt(n);
    for(ll i=1;i<=n;++i) b[i]=i/len;
    for(ll i=1;i<=m;++i) modify(a[i].l,a[i].r,a[i].h);
    ll y=0;
    for(ll i=1;i<=n;++i)
        if(max(w[i],hgt[b[i]])!=y){
            y=max(w[i],hgt[b[i]]);
            cout<<i<<" "<<y<<" ";
        }
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}