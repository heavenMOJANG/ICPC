#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    int minn=1e16,p=0;
    for(int i=m-1;i>=0;i--){
        minn=min(minn,p+a[i]);
        p+=b[i];
    }
    for(int i=m;i<n;i++) minn+=min(a[i],b[i]);
    cout<<minn<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
