#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    int ans=0; 
    for(int i=n-2;i>=0;--i){
        if(a[i]<=a[i+1]) continue;
        int x=a[i+1],t=(a[i]+x-1)/x;
        a[i]=a[i]/t; 
        ans+=t-1;
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
