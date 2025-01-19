#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,q;cin>>n>>q;
    vector<int>a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0,x;i<q;++i)
        cin>>x,cout<<min(a[0]-1,x)<<" ";
    cout<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}