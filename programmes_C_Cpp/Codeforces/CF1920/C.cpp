#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;++i) cin>>a[i];
    int cnt=0;
    for(int k=1;k<=n;++k)
        if(n%k==0){
            int p=0;
            for(int j=1;j+k<=n;++j) p=__gcd(p,abs(a[j+k]-a[j]));
            if(p!=1) cnt++;
        }
    cout<<cnt<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
