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
    int cnt=0;
    for(int i=0;i<n;++i) cin>>a[i];
    int ans=0;
    for(int i=1;i<n;++i){
        int l=a[i-1],r=a[i],tmp=0;
        while(l<r) tmp--,l<<=1;
        while(l>r) tmp++,r<<=1;
        cnt=max(0ll,cnt+tmp);
        ans+=cnt;    
    }
    cout<<ans<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
