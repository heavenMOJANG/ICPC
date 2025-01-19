#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,m;cin>>n>>m;
    vector<vector<char>>g(n,vector<char>(m));
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j) cin>>g[i][j];
    if(n==1){cout<<(g[0][0]==g[0][m-1]?"YES\n":"NO\n");return;}
    if(m==1){cout<<(g[0][0]==g[n-1][0]?"YES\n":"NO\n");return;}
    if(g[0][0]==g[n-1][m-1]||g[0][m-1]==g[n-1][0]){cout<<"YES\n";return;}
    if(g[0][0]==g[0][m-1])
        for(int j=0;j<m;++j) if(g[n-1][j]==g[0][0]){cout<<"YES\n";return;}
    if(g[0][0]==g[n-1][0])
        for(int i=0;i<n;++i) if(g[i][m-1]==g[0][0]){cout<<"YES\n";return;}
    if(g[0][m-1]==g[n-1][m-1])
        for(int i=0;i<n;++i) if(g[i][0]==g[0][m-1]){cout<<"YES\n";return;}
    if(g[n-1][0]==g[n-1][m-1])
        for(int j=0;j<m;++j) if(g[0][j]==g[n-1][0]){cout<<"YES\n";return;}
    cout<<"NO\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}