#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    map<int,vector<int>>mp;
    vector<int>a(n+1);
    for(int i=1;i<=n;++i) cin>>a[i],mp[a[i]>>2].emplace_back(a[i]);
    for(auto [x,y]:mp) sort(y.begin(),y.end());
    for(int i=n;i;--i) a[i]=mp[a[i]>>2].back(),mp[a[i]>>2].pop_back();
    for(int i=1;i<=n;++i) cout<<a[i]<<" \n"[i==n];
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}