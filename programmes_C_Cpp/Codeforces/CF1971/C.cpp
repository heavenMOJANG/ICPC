#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int a,b,c,d;cin>>a>>b>>c>>d;
    if(a>b) swap(a,b);
    if(c>d) swap(c,d);
    int flag=0;
    if(a<=c&&c<=b) flag^=1;
    if(a<=d&&d<=b) flag^=1;
    cout<<(flag?"YES\n":"NO\n");
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}