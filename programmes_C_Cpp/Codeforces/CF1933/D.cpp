#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    cin>>a[0];
    int gcd=a[0];
    for(int i=1;i<n;++i) cin>>a[i],gcd=__gcd(gcd,a[i]);
    int cnt=0;
    for(int i=0;i<n;++i) a[i]/=gcd,cnt+=(a[i]==1);
    cout<<(cnt<=1?"YES\n":"NO\n");
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
