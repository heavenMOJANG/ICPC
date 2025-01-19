#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int x,n;cin>>x>>n;
    int maxn=1;
    for(int i=1;i<=sqrt(x);++i)
        if(x%i==0){
            int j=x/i;
            if(n*i<=x) maxn=max(maxn,i);
            if(n*j<=x) maxn=max(maxn,j);
        }
    cout<<maxn<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
