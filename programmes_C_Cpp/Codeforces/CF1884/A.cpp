#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int x,k;cin>>x>>k;
    auto check=[&](int x,int k)->int
    {
        int res=0;
        while(x){
            res+=x%10;
            x/=10;
        }
        return res%k==0;
    };
    for(int i=x;i<=x+18;++i)
        if(check(i,k)){cout<<i<<"\n";return;}
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
