#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    vector<int>v;
    for(int i=0;i<n;++i) if(s[i]=='1') v.push_back(i);
    if(v.size()&1){cout<<"NO\n";return;}
    if(v.size()==2&&v[0]+1==v[1]){cout<<"NO\n";return;}
    cout<<"YES\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
