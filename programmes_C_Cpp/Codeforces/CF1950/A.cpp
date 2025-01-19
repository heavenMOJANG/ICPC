#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int a,b,c;cin>>a>>b>>c;
    if(a<b){
        if(b<c) cout<<"STAIR\n";
        else if(b>c) cout<<"PEAK\n";
        else cout<<"NONE\n";
    }
    else cout<<"NONE\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
