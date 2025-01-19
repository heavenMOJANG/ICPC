#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    int sum=0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j) sum+=std::max(i,j);
    cout<<sum<<" "<<2*n<<"\n";
    for(int i=n;i;--i){
        cout<<"1 "<<i;
        for(int j=1;j<=n;++j) cout<<" "<<j;
        cout<<"\n2 "<<i;
        for(int j=1;j<=n;++j) cout<<" "<<j;
        cout<<"\n";
    }
    return;
}
signed main(){
    std::cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}