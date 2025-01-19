#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
c//onstexpr int inf=0x7fffffff;
void solve(){
    int n,x,y;cin>>n>>x>>y;
    for(int i=1;i<y;++i) cout<<"-1 ";
    for(int i=y;i<=x;++i) cout<<"1 ";
    for(int i=x+1;i<=n;++i) cout<<"-1 ";
    cout<<"\n";
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}