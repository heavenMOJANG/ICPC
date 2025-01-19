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
    for(int i=0;i<n;++i) cin>>a[i],a[i]*=(i&1?-1:1);
    map<int,int>mp;mp[0]=1;
    int s=0;
    for(int i=0;i<n;++i){
        s+=a[i];
        if(mp.count(s)){cout<<"YES\n";return;}
        mp[s]=1;
    }
    cout<<"NO\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
