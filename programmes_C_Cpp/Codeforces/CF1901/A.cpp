#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,x;cin>>n>>x;
    vector<int>a(n+1,0);
    for(int i=1;i<=n;++i) cin>>a[i];
    int ans=2*(x-a[n]);
    for(int i=1;i<=n;++i) ans=max(ans,a[i]-a[i-1]);
    cout<<ans<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
