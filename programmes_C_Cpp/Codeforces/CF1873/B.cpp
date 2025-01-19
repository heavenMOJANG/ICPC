#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
void solve(){
    ll n;cin>>n;
    vector<ll>a(n);
    for(ll i=0;i<n;++i) cin>>a[i];
    sort(a.begin(),a.end());
    ll res=a[0]+1;
    for(ll i=1;i<n;++i) res*=a[i];
    cout<<res<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
