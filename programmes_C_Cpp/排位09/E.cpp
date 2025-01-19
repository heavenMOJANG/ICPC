#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int mod=1000000007;
int idx;
void solve(){
    cout<<"Case #"<<++idx<<": ";
    int n;cin>>n;
    auto qpow=[&](int a,int n){
        int res=1;
        while(n){
            if(n&1) res=res*a%mod;
            a=a*a%mod;
            n>>=1;
        }
        return res;
    };
    cout<<n%mod*qpow(2,n-1)%mod<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
