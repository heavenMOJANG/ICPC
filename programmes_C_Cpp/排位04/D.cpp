#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,m;cin>>n>>m;
    int gcd=__gcd(n,m);
    auto euler=[&](int x){
        int res=x;
        for(int i=2;i<=x/i;++i)
            if(x%i==0){
                res=res/i*(i-1);
                while(x%i==0) x/=i;
            }
        if(x>1) res=res/x*(x-1);
        return res;
    };
    cout<<euler(m/gcd)<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
