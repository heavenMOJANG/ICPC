#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,m,k;cin>>n>>m>>k;
    int res=n+m-2;
    if(res>k||((k-res)&1)){cout<<"NO\n";return;}
    cout<<"YES\n";
    char s[2]={'R','B'};
    vector<vector<int>>g1(20,vector<int>(20,0)),g2(20,vector<int>(20,0));
    int cur=0;
    for(int i=0;i<n;++i)
        for(int j=1;j<m;++j) g1[i][j]=(j&1)?cur:1-cur;
    if(m%2==0) cur=1;
    for(int i=1;i<n;++i)
        for(int j=1;j<=m;++j) g2[i][j]=(i&1)?cur:1-cur;

    if(g1[0][2]==g2[1][1]) g2[1][1]=g2[1][2]=1-g1[0][2];
    if(g1[1][1]==g2[1][1]) g1[1][1]=1-g2[1][1];
    if(g1[n-1][m-1]==g2[n-1][m]) g1[n-1][m-1]=g1[n-2][m-1]=1-g2[n-1][m];
    for(int i=0;i<n;++i){
        for(int j=1;j<m;++j) cout<<s[g1[i][j]]<<" ";
        cout<<"\n";
    }
    for(int i=1;i<n;++i){
        for(int j=1;j<=m;++j) cout<<s[g2[i][j]]<<" ";
        cout<<"\n";
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
