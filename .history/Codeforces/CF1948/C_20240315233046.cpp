#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    string g[2];cin>>g[0]>>g[1];
    vector<vector<int>>v(2,vector<int>(n,0));
    v[0][0]=1;v[0][1]=1;v[1][0]=1;
    for(int i=0;i<2;++i)
        for(int j=1;j<n;++j) if(g[i][j-1]=='>') v[i][j]=1;
    for(int i=0;i<2;++i)
        for(int j=1;j<n;++j){
            if(!i){
                if((j&1&&v[0][j-1])||((j-1)&1&&v[1][j])) v[i][j]=1;
            }
            else{
                if(((j&1&&v[0][j])||((j-1)&1&&v[1][j-1]))) v[i][j]=1;
            }
        }
    cout<<(v[1][n-1]?"YES\n":"NO\n");
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
