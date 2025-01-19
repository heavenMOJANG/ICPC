#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>a(n+10);
    for(int i=1;i<=n;++i) cin>>a[i];
    int l=0,r=n;
    if(a[1]==a[n]) {
        for(int i=1;i<=n;++i) if(a[i]!=a[1]){l=i;break;}
        for(int i=n;i>=1;--i) if(a[i]!=a[n]){r=i;break;}
        if(l==0&&r==n) cout<<"0\n";
        else cout<<r-l+1<<"\n";
    }
    else{
        for(int i=1;i<=n;++i) if(a[i]!=a[1]){l=i;break;}
        for(int i=n;i>=1;--i) if(a[i]!=a[n]){r=i;break;}
        cout<<min(n-l+1,r)<<"\n";
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
