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
    vector<ll>a(n+10),s(n+10);
    for(ll i=1;i<=n;++i) cin>>a[i]>>s[i];
    ll minn=LLONG_MAX;
    for(ll i=1;i<=n;++i){
        if(s[i]%2==0) minn=min(minn,a[i]+s[i]/2-1);
        else minn=min(minn,s[i]/2+a[i]);
    }
    cout<<minn<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
