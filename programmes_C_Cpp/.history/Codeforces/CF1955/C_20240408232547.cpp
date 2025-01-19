#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,k;cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    int l=0,r=n-1,ans=0;
    while(l<r){
        if(!k) break;
        int tmp=min(a[l],a[r]);
        if(k>=2*tmp){
            k-=2*tmp;
            a[l]-=tmp;
            a[r]-=tmp;
            if(!a[l]) l++,ans++;
            if(!a[r]) r--,ans++;
        }
        else break;
    }
    if(l<r){
        if(a[l]<=a[r]) ans+=(a[l]*2-1<=k);
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