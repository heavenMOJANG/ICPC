#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int a,b;cin>>a>>b;
    int ans=0;
    for(int i=1;i<=a/i;++i)
        for(int j=1;j<=b/j;++j)
            if(__gcd(i,j)==1){
                int cnt=min(a/(i+j)*i,b/(i+j)*j);
                if(cnt>=1) ans+=cnt;
            }
    cout<<ans<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}