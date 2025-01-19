#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    vector<int>a(3);
    for(int i=0;i<3;++i) cin>>a[i];
    sort(a.begin(),a.end());
    for(int i=0;i<5;++i){
        a[0]++;
        sort(a.begin(),a.end());
    }
    cout<<a[0]*a[1]*a[2]<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}