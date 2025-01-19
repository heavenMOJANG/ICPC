#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;++i) cin>>a[i];
    int now=1;
    for(now=4;now<=n;now*=2)
        for(int j=now/2+1;j+1<=min(now,n);j++)
            if(a[j]>a[j+1]){cout<<"NO\n";return;}
    for(int j=now/2+1;j+1<=min(now,n);j++)
        if(a[j]>a[j+1]){cout<<"NO\n";return;}
    cout<<"YES\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
