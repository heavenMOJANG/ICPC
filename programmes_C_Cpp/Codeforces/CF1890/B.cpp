#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,m;cin>>n>>m;
    string s,t;cin>>s>>t;
    int fs=1,ft=1;
    for(int i=1;i<n;++i) if(s[i]==s[i-1]) fs=0;
    if(fs){cout<<"YES\n";return;}
    for(int i=1;i<m;i++) if(t[i]==t[i-1]) ft=0;
    if(!ft){cout<<"NO\n";return;}
    int f1=0,f0=0;
    for(int i=1;i<n;++i){
         if(s[i]=='1'&&s[i-1]=='1') f1=1;
        if(s[i]=='0'&&s[i-1]=='0') f0=1;
    }
    if(f1&&f0){cout<<"NO\n";return;}
    if((f1&&t[0]=='0'&&t[m-1]=='0')||(f0&&t[0]=='1'&&t[m-1]=='1')) cout<<"YES\n";
    else cout<<"NO\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
