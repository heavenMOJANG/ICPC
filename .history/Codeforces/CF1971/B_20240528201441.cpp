#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    string s;cin>>s;
    map<char,int>mp;
    for(int i=0;i<s.size();++i) mp[s[i]]++;
    if(mp.size()==1){cout<<"NO\n";return;}
    else cout<<"YES\n";
    string ans1="",ans2="";
    for(auto [x,y]:mp)
        for(int i=0;i<y;++i) ans1=ans1+x,ans2=x+ans2;
    if(s==ans1) cout<<ans2<<"\n";
    else cout<<ans1<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}