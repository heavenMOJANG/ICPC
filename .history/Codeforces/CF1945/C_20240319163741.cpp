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
    vector<int>a(n+2,0),pre(n+2,0);
    for(int i=0;i<n;++i){
        if(s[i]=='1') a[i+1]=1;
        pre[i+1]=pre[i]+a[i+1];
    }
    pre[n+1]=pre[n];
    int l0=0,r1=pre[n+1];
    if(l0/2*2>=l0&&r1/2*2>=r1){cout<<"0\n";return;}
    for(int i=1;i<=n;++i){
        l0=i-pre[i],r1=pre[n+1]-pre[i-1];
        if(l0/2*2>=l0&&r1/2*2>=r1){cout<<i<<"\n";return;}
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
