#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    int cur=1;
    for(int i=0,x;i<n;++i){
        cin>>x;
        int f=cur%x;
        if(f) f=x-f;
        cur+=(f+1);
    }
    cout<<cur-1<<'\n';
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
