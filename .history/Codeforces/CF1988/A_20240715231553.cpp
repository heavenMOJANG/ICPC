#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,k;cin>>n>>k;
    if(n==1){cout<<"0\n";return;}
    if(n==k){cout<<"1\n";return;}
    int q=n/(k*(k-1)),ans=q*k;
    n%=k*(k-1);
    ans+=n%k?n/k+2:n/k+1;
    cout<<ans<<"\n";
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}