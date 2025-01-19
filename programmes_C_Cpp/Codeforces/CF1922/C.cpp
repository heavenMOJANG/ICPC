#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>a(n+2,0),l(n+1,0),r(n+1,0);
    a[0]=-inf;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(i==1) continue;
        l[i]=l[i - 1];
        if(a[i]-a[i-1]<a[i-1]-a[i-2]) l[i]+=(a[i]-a[i-1])-1;
    }
    a[n+1]=inf;
    for(int i=n-1;i>=1;--i){
        r[i]=r[i+1];
        if(a[i+1]-a[i]<a[i+2]-a[i+1]) r[i]+=(a[i+1]-a[i])-1;
    }
    int q;cin>>q;
    while(q--){
        int x,y;cin>>x>>y;
        cout<<(x<y?a[y]-a[x]-(l[y]-l[x]):a[x]-a[y]-(r[y]-r[x]))<<"\n";
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
