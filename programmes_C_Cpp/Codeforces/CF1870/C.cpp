#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
void solve(){
    ll n,k;cin>>n>>k;
    vector<ll>a(n+1),l(k),r(k);
    for(ll i=1;i<=n;++i){
        cin>>a[i],a[i]--;
        if(!l[a[i]]) l[a[i]]=i;
        r[a[i]]=i;
    }
    ll left=n,right=1;
    vector<ll>ans(k);
    for(ll i=k-1;i>=0;--i){
        if(l[i]) left=min(left,l[i]);
        right=max(right,r[i]);
        if(l[i]) ans[i]=2*(right-left+1);
    }
    for(ll i=0;i<k;++i) cout<<ans[i]<<" \n"[i==k-1];
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
