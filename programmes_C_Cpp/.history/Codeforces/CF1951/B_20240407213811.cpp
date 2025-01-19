#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,k;cin>>n>>k;
    vector<int>a(n+1);
    for(int i=1;i<=n;++i) cin>>a[i];
    int ans=0,cur=1;
    auto cal=[&](int x){
        int res=0;
        for(int i=2;i<=n;++i){
            if(a[i]>a[cur]) cur=i;
            ans+=(cur==x);
        }
        return res;
    };
    swap(a[1],a[k]);
    
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
