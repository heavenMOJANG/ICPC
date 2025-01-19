#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    vector<int>p(5,0);
    int xorSum=0;
    for(int i=1;i<=4;++i){
        cin>>p[i];
        if(p[i]&1) xorSum^=i;
    }
    int ans=0;
    if(!xorSum) ans++;
    for(int i=1;i<=4;++i)
        for(int j=0;j<p[i];++j){
            xorSum^=i;
            if(xorSum) ans++;
            xorSum^=i;
        }
    cout<<ans<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}