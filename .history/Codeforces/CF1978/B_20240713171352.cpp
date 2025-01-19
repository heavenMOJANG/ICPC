#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,a,b;cin>>n>>a>>b;
    if(b<=a){cout<<n*a<<"\n";return;}
    int k=b-a;
    if(k>=n) cout<<(2*b-n+1)*n/2<<"\n";
    else cout<<(2*b-n+1)*k/2+(n-k)*a<<"\n";
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}