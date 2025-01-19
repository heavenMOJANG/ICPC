#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    map<int,int>mp;
    for(int i=0,x;i<3;++i) cin>>x,mp[x]++;
    for(auto it=mp.begin();it!=mp.end();++it) if(it->second==1) cout<<it->first<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
