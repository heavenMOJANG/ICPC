#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int mod=998244353;
void solve(){
    int n;cin>>n;
    vector<int>a(n),b(n);
    for(int i=0,x;i<n;++i) cin>>a[i],a[i]=a[i]*(n-i)*(i+1);
    for(int i=0;i<n;++i) cin>>b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int sum=0;
    for(int i=0;i<n;++i) sum=(sum+a[i]%mod*b[n-i-1]%mod)%mod;
    cout<<sum;
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
