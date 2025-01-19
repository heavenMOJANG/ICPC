#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,m;cin>>n>>m;
    vector<vector<int>>a(n,vector<int>(m));
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j) cin>>a[i][j];
    if(n==1&&m==1){cout<<"-1\n";return;}
    if(m==1){
        for(int i=1;i<n;++i) cout<<a[i][0]<<"\n";
        cout<<a[0][0]<<"\n";
        return;
    }
    for(int i=0;i<n;++i){
        for(int j=1;j<m;++j) cout<<a[i][j]<<" ";
        cout<<a[i][0]<<"\n";
    }
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}