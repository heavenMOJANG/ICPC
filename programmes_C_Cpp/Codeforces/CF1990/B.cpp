#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,x,y;cin>>n>>x>>y;
    vector<int>a(n+1,-1);
    for(int i=y;i<=x;++i) a[i]=1;
    for(int i=x+2;i<=n;i+=2) a[i]=1;
    for(int i=y-2;i>=1;i-=2) a[i]=1;
    for(int i=1;i<=n;++i) cout<<a[i]<<" \n"[i==n];
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}