#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>a(n),x(n);
    for(int i=1;i<n;++i) cin>>x[i];
    a[0]=1000;
    for(int i=1;i<n;++i) a[i]=a[i-1]+x[i];
    for(int i=0;i<n;++i) cout<<a[i]<<" \n"[i==n-1];
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}