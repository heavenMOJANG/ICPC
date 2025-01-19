#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
ll n,a[60],sum;
void solve(){
    cin>>n;
    sum=0;
    for(ll i=1;i<=n;++i) cin>>a[i],sum+=a[i];
    if(sum&1) cout<<"NO\n";
    else cout<<"YES\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}