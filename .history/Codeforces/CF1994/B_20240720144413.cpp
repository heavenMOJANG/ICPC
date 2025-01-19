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
    int flag=1;
    for(int i=0;i<n;++i){
        if(s[i]=='1') break;
        if(s[i]!=t[i]&&s[i]=='0'){flag=0;break;}
    }
    cout<<(flag?"YES\n":"NO\n");
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}