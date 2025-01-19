#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
void solve(){
    ll n,x;cin>>n>>x;
    vector<ll>a(n+1),s(n+1);
    for(ll i=0;i<n;++i) cin>>a[i];
    a[n]=2e9;
    sort(a.begin(),a.end());
    s[0]=a[0];
    for(ll i=1;i<=n;++i) s[i]=s[i-1]+a[i];
    ll p=0;
    for(ll i=1;i<=n;++i){
        ll tmp=(i+1)*a[i]-s[i];
        if(tmp>x) break;
        else p=i; 
    }
    ll h=a[p];
    ll res=x-((p+1)*a[p]-s[p]);
    h+=res/(p+1);
    cout<<h<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
