#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>a(n),p(n);
    for(int i=0;i<n;++i) cin>>a[i];
    int cur;
    if(a[0]==1) p[0]=0,cur=1;
    else p[0]=-a[0],cur=0;
    for(int i=1;i<n;++i){
        p[i]=*s.begin()-a[i];
    }
    for(int i=0;i<n;++i) cout<<p[i]<<" \n"[i==n-1];
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
