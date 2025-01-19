#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    string s,t;cin>>s>>t;
    if(s<t) swap(s,t);
    int n=s.size();
    for(int i=0;i<s.size();++i)
        if(s[i]>t[i]&&s>t) swap(s[i],t[i]);
        else if(s[i]<t[i]&&s<t) swap(s[i],t[i]);
    cout<<t+"\n"+s+"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}