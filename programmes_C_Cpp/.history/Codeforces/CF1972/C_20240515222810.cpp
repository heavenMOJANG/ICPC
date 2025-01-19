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
    sort(a.begin(),a.end());
    int maxn=a[0];
    for(int i=1;i<n;++i)
        if(i*(a[i]-a[i-1])<=k){
            maxn=a[i];
            k-=i*(a[i]-a[i-1]);
        }
        else{
            maxn+=k/i;
            k%=i;
            break;
        }
    int ans=maxn*n+k;
    for(int i=0;i<n;++i) if(a[i]>maxn) ans++;
    cout<<max(0,maxn-n+1)<<"\n";
    return;
}
signed main(){
    std::cin.tie(0)->sync_with_stdio(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}