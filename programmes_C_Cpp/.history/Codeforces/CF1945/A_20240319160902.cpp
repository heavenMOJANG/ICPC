#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int a,b,c;cin>>a>>b>>c;
    a+=b/3;
    b%=3;
    if(c<3-b){cout<<"-1\n";return;}
    else{
        int d=b+c;
        a+=d/3+(d%3==0?0:1);
    }
    cout<<a<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
 