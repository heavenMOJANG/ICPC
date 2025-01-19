#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    string s[n+1];
    for(int i=0;i<n;++i) cin>>s[i];
    int m=n/2,res=0;
    for(int i=0;i<m;++i) {
        for (int j=i;j<n-1-i;++j){
            char a[4]={s[i][j],s[j][n-1-i],s[n-1-i][n-1-j],s[n-1-j][i]};
            char maxn=a[0];
            for(int k=1;k<4;++k) maxn=max(maxn,a[k]);
            for(int k=0;k<4;++k) res+=maxn-a[k];
        }
    }
    cout<<res<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
