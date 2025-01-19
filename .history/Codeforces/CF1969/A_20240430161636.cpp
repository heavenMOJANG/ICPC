#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>p(n+1);
    for(int i=1;i<=n;++i) cin>>p[i];
    int found=0;
    for(int i=1;i<=n;++i) if(p[p[i]]==i) found=1;
    cout<<(found?"2\n":"3\n");
    return;
}
signed main(){
    std::cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}