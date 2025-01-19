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
    auto query1=[&](int x){
        if(x<3) return 0ll;
        return x*(x-1)*(x-2)/6;
    };
    auto query2=[&](int x){
        if(x<2) return 0ll;
        return x*(x-1)/2;
    };
    int res=0;
    for(auto [x,y]:mp) res+=query1(y);
    int now=0;
    for(auto [x,y]:mp) res+=query2(y)*now,now+=y;
    cout<<res<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}