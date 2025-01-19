#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>a(n+1,vector<int>(m+1));
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j) cin>>a[i][j];
    vector<vector<int>> f(n+1,vector<int>(m+1,0));
    auto check=[&](int x) -> bool {
        f[1][1]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i==1&&j==1) continue;
                if((f[i][j-1]||f[i-1][j])&&a[i][j]%x==0) f[i][j]=1;
                else f[i][j]=0;
            }
        }
        return f[n][m];
    };
    int ans=0;
    int y=a[1][1];
    for(int i=1;i*i<=y;i++){
        if(y%i) continue;
        if(check(i)) ans=max(ans,i);
        if(check(y/i)) ans=max(ans,y/i);
    }
    cout<<ans<<'\n';
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}