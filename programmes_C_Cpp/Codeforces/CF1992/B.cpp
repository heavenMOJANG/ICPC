#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,k;cin>>n>>k;
    vector<int>a(k);
    for(int i=0;i<k;++i) cin>>a[i];
    sort(a.begin(),a.end());
    int sum=0;
    for(int i=0;i<k-1;++i) sum+=2*a[i]-1;
    cout<<sum<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}