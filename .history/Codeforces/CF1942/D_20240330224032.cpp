#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,k;cin>>n>>k;
    if(k==1) for(int i=0;i<n;++i) cout<<1<<" \n"[i==n-1];
    else if(n==k-1) for(int i=0;i<n;++i) cout<<i<<" \n"[i==n-1];
    else cout<<"-1\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
