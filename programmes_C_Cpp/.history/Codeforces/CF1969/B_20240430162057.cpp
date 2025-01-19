#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    string s;cin>>s;
    if(is_sorted(s.begin(),s.end())){cout<<"0\n";return;}
    int p=0;
    while(s[p]!='1') p++;
    int ans=0,cnt=0;
    for(int i=p+1;i<s.size();++i)
        if(s[i]=='0') ans+=i-p+1+cnt,cnt++;
    cout<<ans<<"\n";
    return;
}
signed main(){
    std::cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}