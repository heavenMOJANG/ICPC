#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int a,c;cin>>a>>c;
    if(c%a!=0){cout<<"NO SOLUTION\n";return;}
    int i=1,d=c/a;
    while(i*d!=d*__gcd(a,i*d)) i++;
    cout<<i*d<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
