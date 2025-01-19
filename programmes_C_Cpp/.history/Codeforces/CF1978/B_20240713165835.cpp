#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,a,b;cin>>n>>a>>b;
    int ans=n*a,k=b-a;
    if(k){
        int l=k,r=max(0ll,k-n+1);
        ans+=(l+r)*(l-r+1)/2;
    }
    cout<<ans<<"\n";
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}