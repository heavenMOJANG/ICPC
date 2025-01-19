#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,x,y;cin>>n>>x>>y;
    if(n-y+1<x){
        for(int i=1;i<n-y+1;++i) cout<<"-1 ";
        for(int i=n-y+1;i<=x;++i) cout<<"1 ";
        for(int i=x+1;i<=n;++i) cout<<"-1 ";
    }
    else{
        for(int i=1;i<=n;++i)
        if(i==x||i==n-y+1) cout<<"1 ";
        else cout<<"-1 ";
    }
    cout<<"\n";
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}