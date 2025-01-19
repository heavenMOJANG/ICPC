#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,m;cin>>n>>m;
    vector<int>a(n+1),b(m+1);
    for (int i=1;i<=n;++i) cin>>a[i];
    for (int j=1;j<=m;++j) cin>>b[j];
    sort(a.begin()+1,a.begin()+1+n);
    sort(b.begin()+1,b.begin()+1+m);
    int ans=0;
    int la=1,ra=n,lb=1,rb=m;
    while(la<=ra)
        if(abs(a[la]-b[rb])>=abs(a[ra]-b[lb])) ans+=abs(a[la++]-b[rb--]);
        else ans+=abs(a[ra--]-b[lb++]);
    cout<<ans<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
