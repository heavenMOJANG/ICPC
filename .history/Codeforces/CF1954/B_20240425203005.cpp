#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    int flag=1;
    for(int i=0;i<n;++i) if(a[i]!=a[0]) flag=0;
    if(flag){cout <<"-1\n";return;}
    int cnt=0,minn=1e9;
    for(int i=0;i<n;++i)
        if(a[i]==a[0]) cnt++;
        else minn=min(minn,cnt),cnt=0;
    if(cnt) minn=min(minn,cnt);
    cout<<minn<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}