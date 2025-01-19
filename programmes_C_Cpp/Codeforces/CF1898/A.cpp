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
    int sumb=0,suma=0;
    vector<int>a(s.size()+2),b(s.size()+2);
    for(int i=0;i<n;++i)
        if(s[i]=='B') b[++sumb]=i+1;
        else a[++suma]=i+1;
    if(k==sumb){cout<<"0\n";return;}
    cout<<"1\n";
    if(k<sumb) cout<<b[sumb-k]<<" A\n";
    else cout<<a[k-sumb]<<" B\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
