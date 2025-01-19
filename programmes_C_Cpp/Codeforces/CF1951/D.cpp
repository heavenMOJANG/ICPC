#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,k;cin>>n>>k;
    if(n==k){cout<<"YES\n1\n1\n";return;}
    if(k==1){cout<<"YES\n1\n"<<n<<"\n";return;}
    if(2*k<=n+1){cout<<"YES\n2\n"<<n-k+1<<" 1\n";return;}
    cout<<"NO\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
