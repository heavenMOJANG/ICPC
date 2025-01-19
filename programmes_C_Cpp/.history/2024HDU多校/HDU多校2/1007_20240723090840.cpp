#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    string s;cin>>s;
    int p=s.find("://");
    cout<<s.substr(0,p)<<"\n";
    s=s.substr(p+3);
    p=s.find("/");
    cout<<s.substr(0,p)<<"\n";
    s=s.substr(p+1);
    cout<<s<<"\n";
    int i = p + 1;
    while (1) {
        p = s.find("/");
        if (p == -1) break;
        if (s.find("=", i, p)) cout << s.substr(i, p) << "\n";
        i = p + 1;
    }
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}