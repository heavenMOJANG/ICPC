#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin >> n;
    int x=__lg(n);
    vector<int>ans;
    for(int i=0;i<x;++i) ans.push_back(i);
    for(int i=x-1;i>=0;--i) if(n>>i&1) ans.push_back(i);
    cout<<ans.size()<<'\n';
    for(int i=0;i<ans.size();++i) cout<<ans[i]<<" \n"[i==ans.size()-1];
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
