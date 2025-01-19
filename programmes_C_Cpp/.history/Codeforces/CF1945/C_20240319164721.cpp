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
    vector<int>p0(n+1,0),p1(n+1,0);
    for(int i=0;i<n;++i){
        p0[i+1]+=p0[i];
        p1[i+1]+=p1[i];
        if(s[i]=='0') 
    }
    int l0=n-pre[n],r1=pre[n];
    if(r1*2>=n){cout<<"0\n";return;}
    if(l0*2>=n){cout<<n<<"\n";return;}
    for(int i=1;i<=n;++i){
        l0=i-pre[i],r1=pre[n]-pre[i];
        if(l0*2>=i&&r1*2>=n-i){cout<<i<<"\n";return;}
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
