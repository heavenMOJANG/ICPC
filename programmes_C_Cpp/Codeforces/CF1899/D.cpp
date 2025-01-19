#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>a(n+1),dp(n+1);
    map<int,int>mp;
    for(int i=1;i<=n;++i) cin>>a[i],mp[a[i]]++;
    int ans=0;
    for(auto [x,y]:mp) ans+=y*(y-1)/2;
    ans+=mp[1]*mp[2];
    cout<<ans<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
