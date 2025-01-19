#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;
    cin>>n;
    vector<int>a(n<<1),x(n),y(n);
    for(auto &i:a) cin>>i;
    std::sort(a.begin(),a.end());
    int sum=0;
    for(int i=0;i<n;++i) x[i]=a[i];
    for(int i=n;i<n*2;++i) y[i-n]=a[i];
    reverse(y.begin(),y.end());
    for(int i=1;i<n;++i) sum +=abs(x[i]-x[i-1])+abs(y[i]-y[i-1]);
    cout<<sum<<"\n";
    for(int i=0;i<n;++i) cout<<x[i]<<" "<<y[i]<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
