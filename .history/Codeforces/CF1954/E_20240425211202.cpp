#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;++i) cin>>a[i];
    int m=*max_element(a.begin(),a.end());
    vector<int>d(m+2);
    for(int i=2;i<=n;++i){
        int x=a[i]-1,y=a[i-1]-1;
        if(x<=y) continue;
        for(int l=1,r;l<=m;l=r+1){
            r=min(x/l==0?m:x/(x/l),y/l==0?m:y/(y/l));
            d[l]+=x/l-y/l,d[r+1]-=x/l-y/l;
        }
    }
    vector<int>ans;
    for(int i=1;i<=m;++i){
        d[i]+=d[i-1];
        cout<<d[i]+(a[1]+i-1)/i<<" ";
    }
    cout<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;//cin>>_;
    while(_--) solve();
    return 0;
}