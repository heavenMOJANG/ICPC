#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin >> n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<n;++i) cin>>b[i];
    int ans=0;
        for(int i=0;i<n;++i) ans+=abs(a[i]-b[i]);
        vector<pii>p(n);
        for(int i=0;i<n;++i) p[i]=minmax(a[i],b[i]);
        sort(p.begin(),p.end());
        int maxn=0,minn=inf;
        for(auto [l,r]:p)
            maxn=max(maxn,2*(l-minn)),minn=min(minn,r);
        cout<<ans+maxn<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
