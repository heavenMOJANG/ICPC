#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    map<int,int>mp;
    for(int i=0,x;i<n;++i) {
        cin>>x;
        int m=sqrt(x);
        for(int i=2;i<=m&&x>1;++i)
            while(x%i==0) mp[i]++,x/=i;
        if(x>1) mp[x]++;
    }
    for(auto p:mp) if(p.second%n){cout<<"NO\n";return;}
    cout<<"YES\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
