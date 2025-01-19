#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    map<int,int>mp;
    for(int i=0,x;i<n;++i) cin>>x,mp[x]++;
    if(mp.size()>2){cout<<"No\n";return;}
    if(mp.size()==2){
        int x=mp.begin()->second,y=(--mp.end())->second;
        if(abs(x-y)>1){cout<<"No\n";return;}
    }
    cout<<"Yes\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
