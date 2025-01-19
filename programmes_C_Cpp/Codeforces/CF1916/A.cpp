#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,k;cin>>n>>k;
    int res=1;
    for(int i=0,x;i<n;++i) cin>>x,res*=x;
    if(2023%res){cout<<"NO\n";return;}
    cout<<"YES\n";
    cout<<2023/res;
    for(int i=0;i<k-1;++i) cout<<" 1";
    cout<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
