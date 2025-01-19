#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int N=2e5+10;
vector<int>f(N);
void solve(){
    int n,k;cin>>n>>k;
    if(k&1||k>f[n]){cout<<"NO\n";return;}

    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    for(int i=2;i<N;++i) f[i]=f[i-2]+2*(i-1);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}