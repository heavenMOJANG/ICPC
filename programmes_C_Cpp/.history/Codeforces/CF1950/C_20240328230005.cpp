#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    string s;cin>>s;
    int hh=(s[0]-'0')*10+s[1]-'0';
    int mm=(s[3]-'0')*10+s[4]-'0';
    if(hh==0) cout<<"12:"<<mm<<" AM\n";
    else if(hh<12) cout<<hh<<":"<<mm<<" AM\n";
    else if(hh==12) cout<<"12:"<<mm<<" AM\n";
    else if(hh<22) cout<<"0"<<hh-12<<":"<<mm<<" PM\n";
    else cout<<hh-12<<":"<<mm<<" PM\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
