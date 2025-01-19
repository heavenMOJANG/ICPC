#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
map<int,int>mp;
void solve(){
    int x;cin>>x;
    if(mp[x]==1){cout<<"-1\n";return;}
    cout<<x-1<<"\n";
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    mp[1]=1;
    for(int i=1;i<=63;++i) cin>>
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}