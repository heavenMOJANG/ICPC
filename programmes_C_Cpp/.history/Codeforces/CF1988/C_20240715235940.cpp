#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>b;
    for(int i=0;i<64;++i)
        if(n&(1ll<<i)) b.emplace_back(i);
    set<int>ans;
    ans.insert(n);
    for(int i=0;i<b.size()-1;++i) ans.insert(n^(1ll<<b[i]));
    int x=0;
    for(int i=0;i<b.size()-1;++i) x|=(1ll<<b[i]);
    ans.insert(x);
    for(auto xx:ans) cout<<xx<<" ";
    cout<<"\n";
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}