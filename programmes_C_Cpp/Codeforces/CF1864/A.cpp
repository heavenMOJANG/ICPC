#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int x,y,n;cin>>x>>y>>n;
    vector<int>a(n);
    a[n-1]=y;
    int d=1;
    for(int i=n-2;i>=0;--i){
        a[i]=a[i+1]-d;
        d++;
    }
    if(a[0]>=x){
        a[0]=x;
        for(int i=0;i<n;++i) cout<<a[i]<<" \n"[i==n-1];
    }
    else cout<<"-1\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
