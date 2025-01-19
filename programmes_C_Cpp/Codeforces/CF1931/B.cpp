#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>a(n+10);
    int s=0;
    for(int i=1;i<=n;++i) cin>>a[i],s+=a[i];
    int res=s/n,left=0;
    for(int i=1;i<=n;++i){
        if(a[i]>=res) left+=(a[i]-res);
        else
            if(a[i]<res) left-=(res-a[i]);
        if(left<0){cout<< "NO\n";return;}
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
