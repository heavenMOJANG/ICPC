#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    string s,t;cin>>s>>t;
    int a=0,b=0;
    for(int i=0;i<n;++i){
        if(s[i]>t[i]) a++;
        if(s[i]<t[i]) b++;
    }
    cout<<max(a,b)<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
