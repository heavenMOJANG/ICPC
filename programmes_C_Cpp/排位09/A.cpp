#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int mod=1000000;
void solve(){
    vector<vector<int>>a(210,vector<int>(210,0));
    a[0][0]=1;
    for(int i=1;i<=200;i++){
        a[i][0]=a[i][200]=1;
        for(int j=1;j<200;++j)
            a[i][j]=(a[i-1][j]%mod+a[i-1][j-1]%mod)%mod;
    }
    int n,k;
    while(cin>>n>>k,n||k) cout<<a[n+k-1][k-1]<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
