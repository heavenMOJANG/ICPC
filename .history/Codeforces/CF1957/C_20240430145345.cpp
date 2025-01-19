#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int N=3e5+10;
constexpr int mod=1e9+7;
int fac[N],inv[N];
void init(){
    fac[0]=inv[0]=1;
    for(int i=1;i<N;++i) fac[i]=fac[i-1]*i%mod;
}
void solve(){
    int n;cin>>n;
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}