#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,k;cin>>n>>k;
    vector<int>v(n,0);
    int cur=0;
    while(k>0){
        for(int i=0;i<n&&k>0;++i) {
            v[i]+=(1ll<<cur);
            k--;
        }
        cur++;
    }
    for(int i=0;i<n;++i) cout<<v[i]<<" \n"[i==n-1];
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}