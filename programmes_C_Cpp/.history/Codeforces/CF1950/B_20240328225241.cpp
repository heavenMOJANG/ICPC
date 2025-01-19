#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;n<<=1;
    vector<vector<char>>g(n,vector<char>(n));
    vector<char>ch(2);
    ch[0]='.';ch[1]='#';
    int rflag=1,cflag=1;
    for(int i=0;i<n;i+=2){
        for(int j=0;j<n;j+=2){
            g[i][j]=g[i][j+1]=g[i+1][j]=g[i+1][j+1]=ch[cflag];
            cflag^=1;
        }
        rflag^=1;
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j) cout<<g[i][j];
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
