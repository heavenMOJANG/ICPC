#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    if(n&1){cout<<"NO\n";return;}
    cout<<"YES\n";
    int flag=0;
    for(int i=1;i<=n;i+=2){
        if(flag) cout<<"AA";
        else cout<<"BB";
        flag^=1;
    }
    cout<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
