#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,k,x;cin>>n>>k>>x;
    vector<int>a(n+1,0);
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a.begin()+1,a.begin()+n+1);
    for(int i=2;i<=n;++i) a[i]+=a[i-1];
    int maxn=LLONG_MIN;
    for(int i=0;i<=k;++i)
        maxn=max(maxn,(n-i>x)?2*a[n-i-x]-a[n-i]:-a[n-i]);
    cout<<maxn<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
