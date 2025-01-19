#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
void solve(){
    ll n,k;cin>>n>>k;
    vector<ll>a(n),h(n);
    for(ll i=0;i<n;++i) cin>>a[i];
    for(ll i=0;i<n;++i) cin>>h[i];
    ll l=0,r=-1,maxl=0,sum=0;
    while(l<n&&r<n){
        if(r+2==l) r++,sum+=a[r];
        while(r+1<n&&(r+1==l||h[r]%h[r+1]==0)&&sum+a[r+1]<=k) r++,sum+=a[r];
        maxl=max(maxl,r-l+1);
        sum-=a[l];
        l++; 
    }
    cout<<maxl<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
