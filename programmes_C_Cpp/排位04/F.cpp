#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<vector<char>>g(15,vector<char>(15,'.'));
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j) cin>>g[i][j];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j){
            if(g[i][j]!='.') continue;
            for(char c='A';c<='Z';++c){
                if(i>1&&c==g[i-1][j]) continue;
                if(j>1&&c==g[i][j-1]) continue;
                if(j<n&&c==g[i][j+1]) continue;
                if(i<n&&c==g[i+1][j]) continue;
                g[i][j]=c;
                break;
            }
        }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j){
            cout<<g[i][j];
            if(j==n) cout<<"\n";
        }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    for(int i=1;i<=_;++i){
        cout<<"Case "<<i<<":\n";
        solve();
    }
    return 0;
}
