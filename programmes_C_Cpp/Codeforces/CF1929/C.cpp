#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int k,x,a;cin>>k>>x>>a;
    int cur=0;
    for(int i=1,cost;i<=x+1;++i){
        if(i==1) cost=1;
        else cost=cur/(k-1)+1;
        if(cost>a){cout<<"NO\n";return;}
        else cur+=cost,a-=cost;
    }
    cout<<"YES\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
