#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    vector<int>a(5);
    for(int i=1;i<=4;++i) cin>>a[i];
    int ans=0;
    for(int i=1;i<=3;++i) ans+=a[i]&1;
    if(ans==3) ans=1;
    else ans=0;
    for(int i=1;i<=4;++i) ans+=a[i]/2ll;
    cout<<ans<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}