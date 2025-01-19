#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,m;cin>>n>>m;
    vector<vector<int>>a(n,vector<int>(m)),b(n,vector<int>(m));
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j) cin>>a[i][j];
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j) cin>>b[i][j];
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;
    while(_--) solve();
    return 0;
}