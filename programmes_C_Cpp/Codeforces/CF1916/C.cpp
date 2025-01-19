#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>a(n),cnt(n,0),sum(n,0);
    cin>>a[0],sum[0]=a[0],cnt[0]=a[0]&1;
    for(int i=1;i<n;++i){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
        cnt[i]=cnt[i-1]+a[i]%2;
    }
    for(int i=1;i<n;++i){
        if(cnt[i]==1){sum[i]-=1;continue;}
        sum[i]-=(cnt[i]/3)+(cnt[i]%3==1);
    }
    for(int i=0;i<n;++i) cout<<sum[i]<<" \n"[i==n-1];
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
