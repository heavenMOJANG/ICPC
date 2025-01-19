#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n;
void solve(){
    cin>>n;
    vector<ll>a(n);
    for(ll i=0;i<n;++i) cin>>a[i];
    ll l=0,r=n-1;
    while(l<r&&a[l]==1) l++;
    while(l<r&&a[r]==1) r--;
    ll res=1;
    for(ll i=l;i<=r;++i){
        res*=a[i];
        if(res>1e9){cout<<l+1<<" "<<r+1<<"\n";return;}
    }
    vector<ll>p;
    for(ll i=0;i<n;++i) if(a[i]>1) p.push_back(i);
    ll sum=accumulate(a.begin(),a.end(),0);
    ll L=1,R=1,ans=sum;
    for(ll i=0;i<p.size();++i){
        ll l=p[i],tmp=1,s=0;
        for(ll j=i;j<p.size();++j){
            ll r=p[j];
            tmp*=a[r];
            s+=a[r]-1;
            ll v=sum-(r-l+1)-s+tmp;
            if(v>ans) ans=v,L=l+1,R=r+1;
        }
    }
    cout<<L<<" "<<R<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
