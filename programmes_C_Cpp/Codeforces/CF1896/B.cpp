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
    int pa=-1,pb=-1;
    for(int i=0;i<n;++i) if(s[i]=='A'){pa=i;break;}
    for(int i=n-1;i>=0;--i) if(s[i]=='B'){pb=i;break;}
    if(pa==-1||pb==-1||pa>pb){cout<<"0\n";return;}
    cout<<pb-pa<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
