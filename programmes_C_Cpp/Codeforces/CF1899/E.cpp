#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>a(n+1);
    int minn=LLONG_MAX,p=0;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(minn>a[i]) minn=a[i],p=i;
    }
    for(int i=p;i<n;++i) if(a[i]>a[i+1]){cout<<"-1\n";return;}
    cout<<p-1<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
