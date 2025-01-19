#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,m,k;cin>>n>>m>>k;
    vector<int>b(n),c(m);
    for(int i=0;i<n;++i) cin>>b[i];
    int sum=0;
    for(int i=0;i<m;++i){
        cin>>c[i];
        for(int j=0;j<n;++j) if(b[j]+c[i]<=k) sum++;
    }
    cout<<sum<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
