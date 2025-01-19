#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,k;cin>>n>>k;
    string s;cin>>s;
    map<char,int>mp;
    for(auto x:s) mp[x]++;
    int cnt=0;
    for(auto it:mp) if(it.second&1) cnt++;
    cout<<(cnt<=k+1?"YES\n":"NO\n");
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
