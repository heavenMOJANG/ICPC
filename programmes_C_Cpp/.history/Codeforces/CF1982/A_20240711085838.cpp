#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
    if((x1<y1&&x2>y2)||(y1<x1&&y2>x2)) cout<<"NO\n";
    else cout<<"YES\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}